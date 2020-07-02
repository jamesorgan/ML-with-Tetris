#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <shellapi.h>
#include "resource.h"

#define MAX_CLIENTS 512						// コマンドラインで指定できる最大接続数(Max clients can be set in command line)
#define DEFAULT_MAX_CLIENTS 256				// デフォルトの最大接続数(Default max clients)
#define DEFAULT_PORT 5000					// デフォルトで使うポート(Default port)

#define MAX_BUFFER 65536					// 受信／送信用バッファの大きさ
#define SERVER_VERSION 2					// サーバーバージョン

WSADATA wsaData;							// Winsockのバージョンに関するデータ

SOCKET sockets[MAX_CLIENTS + 1];			// ソケット
struct sockaddr_in addr[MAX_CLIENTS + 1];	// IPアドレス、ポート番号を格納
int client_count;							// クライアント接続数
int server_port;							// サーバーのポート番号
int server_maxclients;						// 最大接続数

int client_status[MAX_CLIENTS + 1];			// クライアントの状態（0=メニュー画面 1=相手待ち 2=プレイ中）
int client_engineversion[MAX_CLIENTS + 1];	// クライアントが使っているゲームのエンジンのバージョン
int client_modeversion[MAX_CLIENTS + 1];	// クライアントが使っているモードのバージョン
char client_gamemode[MAX_CLIENTS + 1][32];	// クライアントが使っているモードの名前

long buf_in[MAX_BUFFER];					// 受信用バッファ
long buf_out[MAX_BUFFER];					// 送信用バッファ

HICON hIcon;								// アイコン
NOTIFYICONDATA nIconData;					// トレイアイコンの構造体
UINT mTaskbarCreated;						// トレイアイコン再登録イベントのメッセージ番号

// 受信可能バイト数を調べる
unsigned long ReceiveLength(SOCKET sock) {
	unsigned long result;
	result = 0;
	ioctlsocket(sock, FIONREAD, &result);
	return result;
}

// 初期化
void Init() {
	int i;
	
	for(i = 0; i < server_maxclients + 1; i++) {
		sockets[i] = INVALID_SOCKET;
		client_status[i] = 0;
		client_engineversion[i] = 0;
		client_modeversion[i] = 0;
		strcpy(client_gamemode[i], "");
	}
}

// ソケットの番号を調べる
// 未知のソケットなら-1になる
int IdentifySocketID(SOCKET sock) {
	int i;
	
	for(i = 0; i < server_maxclients + 1; i++) {
		if(sock == sockets[i]) {
			return i;
		}
	}
	
	return -1;
}

// 開いているソケットの番号を返す
int SearchEmptySocketID() {
	int i;
	
	for(i = 0; i < server_maxclients + 1; i++) {
		if(sockets[i] == INVALID_SOCKET) {
			return i;
		}
	}
	
	return -1;
}

// 相手を待っているプレイヤーを探す（自分と同じモードとバージョンのプレイヤーのみ）
int SearchWaitingPlayer(int myid) {
	int i;
	
	for(i = 1; i < server_maxclients + 1; i++) {
		if((client_status[i] == 1) && (strcmp(client_gamemode[myid], client_gamemode[i]) == 0) && 
		   (client_modeversion[myid] == client_modeversion[i]) && (client_engineversion[myid] == client_engineversion[i]) && 
		   (i != myid) && (sockets[i] != INVALID_SOCKET))
		{
			return i;
		}
	}
	
	return -1;
}

// 自分と同じモードとバージョンのプレイヤー数を数える
int CountSameModeAndVersionPlayer(int myid, int mode) {
	int i, result;
	result = 0;
	
	for(i = 1; i < server_maxclients + 1; i++) {
		if((client_status[i] == mode) && (strcmp(client_gamemode[myid], client_gamemode[i]) == 0) && 
		   (client_modeversion[myid] == client_modeversion[i]) && (client_engineversion[myid] == client_engineversion[i]) && 
		   (i != myid) && (sockets[i] != INVALID_SOCKET))
		{
			result++;
		}
	}
	
	return result;
}

// 待ち受け開始
void StartServerListen(HWND hwnd) {
	BOOL reuseaddr = TRUE;
	BOOL nodelay = TRUE;
	
	Init();
	
	sockets[0] = socket(AF_INET, SOCK_STREAM, 0);
	addr[0].sin_family = AF_INET;
	addr[0].sin_port = htons(server_port);
	addr[0].sin_addr.S_un.S_addr = INADDR_ANY;
	setsockopt(sockets[0], SOL_SOCKET, SO_REUSEADDR, (const char *)&reuseaddr, sizeof(reuseaddr));
	setsockopt(sockets[0], IPPROTO_TCP, TCP_NODELAY, (const char *)&nodelay, sizeof(nodelay));
	WSAAsyncSelect(sockets[0], hwnd, WM_USER, FD_ACCEPT | FD_WRITE | FD_READ | FD_CLOSE);
	
	bind(sockets[0], (struct sockaddr *)&addr[0], sizeof(addr[0]));
	listen(sockets[0], server_maxclients);
}

// 接続要求を受け入れる
void AcceptNewClient(SOCKET sock, LONG error) {
	int i, id, len, size;
	
	id = SearchEmptySocketID();
	
	if(id != -1) {
		len = sizeof(addr[id]);
		sockets[id] = accept(sock, (struct sockaddr *)&addr[id], &len);
		client_status[id] = 0;
		client_engineversion[id] = 0;
		client_modeversion[id] = 0;
		strcpy(client_gamemode[id], "");
		client_count++;
		
		// 全プレイヤーに通知
		for(i = 1; i < server_maxclients + 1; i++) {
			if((sockets[i] != INVALID_SOCKET) && (i != id)) {
				size = 5 * 4;
				buf_out[0] = size;				// サイズ
				buf_out[1] = 0;					// 送信元
				buf_out[2] = 1;					// コマンド
				buf_out[3] = id;				// ID
				buf_out[4] = client_count;		// 接続人数
				send(sockets[i], (char *)buf_out, size, 0);
			}
		}
	}
}

// 接続が切断されたとき
void DisconnectClient(SOCKET sock, LONG error) {
	int i, id, size;
	
	id = IdentifySocketID(sock);
	
	if(id != -1) {
		client_count--;
		sockets[id] = INVALID_SOCKET;
		client_status[id] = 0;
		client_engineversion[id] = 0;
		client_modeversion[id] = 0;
		strcpy(client_gamemode[id], "");
		
		// 全プレイヤーに通知
		for(i = 1; i < server_maxclients + 1; i++) {
			if(sockets[i] != INVALID_SOCKET) {
				size = 5 * 4;
				buf_out[0] = size;				// サイズ
				buf_out[1] = 0;					// 送信元
				buf_out[2] = 2;					// コマンド
				buf_out[3] = id;				// ID
				buf_out[4] = client_count;		// 接続人数
				send(sockets[i], (char *)buf_out, size, 0);
			}
		}
	}
}

// データ受信
void ReceiveDataFromClient(SOCKET sock, LONG error) {
	int i;
	int temp;
	int command, id_from, id_to;
	int result;
	int size;
	
	// 最初の4バイトだけを受信（サイズを調べる）
	// （まだキューから除去はしない）
	result = recv(sock, (char *)buf_in, 4, MSG_PEEK);
	if(result == SOCKET_ERROR) return;
	
	// 読み込むサイズを決める
	size = buf_in[0];
	if(size < 1) return;
	
	// データが全て来ているかどうか確認
	// (TODO: Add Mr.DeHackEd's new, excellent buffering system)
	if(ReceiveLength(sock) < size) return;
	
	// 残りのデータを読み込み
	result = recv(sock, (char *)buf_in, size, 0);
	if(result == SOCKET_ERROR) return;
	
	// 送信元IDを判定
	id_from = IdentifySocketID(sock);
	if(id_from == -1) return;
	
	// 受信したデータに応じて処理を行う
	id_to = buf_in[1];
	command = buf_in[2];
	
	// 送信先IDが0（サーバー）だったら
	if(id_to == 0) {
		switch(command) {
			case 0:	// 情報取得
				size = 8 * 4;
				buf_out[0] = size;						// サイズ
				buf_out[1] = 0;							// 送信元
				buf_out[2] = 0;							// コマンド
				buf_out[3] = SERVER_VERSION;			// バージョン
				buf_out[4] = client_count;				// 接続人数
				buf_out[5] = id_from;					// 自分のID
				buf_out[6] = client_status[id_from];	// 自分の状態
				buf_out[7] = server_maxclients;			// 最大接続人数
				send(sock, (char *)buf_out, size, 0);
				break;
			case 1:	// バージョン設定
				client_engineversion[id_from] = buf_in[3];
				client_modeversion[id_from] = buf_in[4];
				strncpy(client_gamemode[id_from], (char *)buf_in + (5 * 4), 32);
				break;
			case 2:	// 自分の状態を変える
				client_status[id_from] = buf_in[3];
				break;
			case 3:	// 対戦相手を探す
				temp = SearchWaitingPlayer(id_from);
				if(temp != -1) {
					// 相手が見つかった
					size = 4 * 4;
					buf_out[0] = size;					// サイズ
					buf_out[1] = 0;						// 送信元
					buf_out[2] = 3;						// コマンド
					buf_out[3] = temp;					// 相手のID
					send(sock, (char *)buf_out, size, 0);
				} else {
					// 見つからない
					size = 3 * 4;
					buf_out[0] = size;					// サイズ
					buf_out[1] = 0;						// 送信元
					buf_out[2] = 4;						// コマンド
					send(sock, (char *)buf_out, size, 0);
				}
				break;
			case 4:	// 自分と同じモードとバージョンのプレイヤー数を取得
				size = 6 * 4;
				buf_out[0] = size;		// サイズ
				buf_out[1] = 0;			// 送信元
				buf_out[2] = 5;			// コマンド
				buf_out[3] = CountSameModeAndVersionPlayer(id_from, 0);	// メニュー画面のプレイヤー数
				buf_out[4] = CountSameModeAndVersionPlayer(id_from, 1);	// 相手待ちのプレイヤー数
				buf_out[5] = CountSameModeAndVersionPlayer(id_from, 2);	// プレイ中のプレイヤー数
				send(sock, (char *)buf_out, size, 0);
				break;
		}
	}
	// 送信先IDが1以上（他のプレイヤー）だったら
	else if((id_to < server_maxclients + 1) && (sockets[id_to] != INVALID_SOCKET) && 
	        (strcmp(client_gamemode[id_from], client_gamemode[id_to]) == 0) && 
	        (client_modeversion[id_from] == client_modeversion[id_to]) && (client_engineversion[id_from] == client_engineversion[id_to]))
	{
		for(i = 0; i < (size / 4); i++) buf_out[i] = buf_in[i];
		buf_out[1] = id_from;	// 送信元
		send(sockets[id_to], (char *)buf_out, size, 0);
	}
}

// タスクトレイにアイコンを登録
BOOL AddTrayIcon(HWND hwnd) {
	char tip[64];
	
	// 構造体を設定
	ZeroMemory(&nIconData, sizeof(nIconData));
	nIconData.cbSize = sizeof(nIconData);
	nIconData.hWnd = hwnd;
	nIconData.uID = 0;
	nIconData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	nIconData.uCallbackMessage = WM_USER + 1;
	nIconData.hIcon = hIcon;
	sprintf(tip, "heboserver (%d,%d)", server_port, server_maxclients);
	strcpy(nIconData.szTip, tip);
	
	// アイコンを登録
	while(1) {
		if(Shell_NotifyIcon(NIM_ADD, &nIconData)) {
			// 登録完了
			return TRUE;
		} else {
			// 少し待機
			Sleep(1000);
			
			if(Shell_NotifyIcon(NIM_MODIFY, &nIconData)) {
				// 登録が完了している
				return TRUE;
			}
		}
	}
}

// サーバーの情報を表示
void DisplayServerInfo() {
	char strMsg[256];
	sprintf(strMsg, "Version:%d\nPort:%d\nMax Clients:%d", SERVER_VERSION, server_port, server_maxclients);
	MessageBox(NULL, strMsg, TEXT("heboserver"), MB_OK | MB_SETFOREGROUND);
}

// イベント処理用ウィンドウの処理
LRESULT CALLBACK ListenerWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch(uMsg) {
		case WM_CREATE:	// 初期化
			mTaskbarCreated = RegisterWindowMessage(TEXT("TaskbarCreated"));	// Explorer復帰メッセージIDを調べる
			AddTrayIcon(hwnd);	// タスクトレイにアイコンを登録
			StartServerListen(hwnd);
			break;
		case WM_USER:	// ソケットイベント
			switch(WSAGETSELECTEVENT(lParam)) {
				case FD_ACCEPT:
					AcceptNewClient((SOCKET)wParam, WSAGETSELECTERROR(lParam));
					break;
				case FD_WRITE:
					break;
				case FD_READ:
					ReceiveDataFromClient((SOCKET)wParam, WSAGETSELECTERROR(lParam));
					break;
				case FD_CLOSE:
					DisconnectClient((SOCKET)wParam, WSAGETSELECTERROR(lParam));
					break;
			}
			break;
		case WM_USER + 1:	// トレイアイコンのイベント
			switch(lParam) {
				case WM_LBUTTONUP:	// 左クリック
					DisplayServerInfo();
					break;
				case WM_RBUTTONUP:	// 右クリック
					if(MessageBox(NULL, TEXT("Quit?"), TEXT("heboserver"), MB_OKCANCEL | MB_SETFOREGROUND) == IDOK) {
						SendMessage(hwnd, WM_CLOSE, 0, 0);
					}
					break;
			}
			break;
		case WM_DESTROY:	// 終了
			Shell_NotifyIcon(NIM_DELETE, &nIconData);	// タスクトレイアイコンを消す
			PostQuitMessage(0);
			return 0;
		default:	// その他
			// Explorerクラッシュ後のトレイアイコン復活
			if(uMsg == mTaskbarCreated) AddTrayIcon(hwnd);
			break;
	}
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// イベント処理用ウィンドウを作成
void CreateListenerWindow(HINSTANCE hinst) {
	WNDCLASS wnd;
	
	hIcon = LoadIcon(hinst, MAKEINTRESOURCE(IDI_ICON1));
	
	ZeroMemory(&wnd, sizeof(wnd));
	wnd.style = CS_NOCLOSE;
	wnd.lpfnWndProc = ListenerWindowProc;
	wnd.hInstance = hinst;
	wnd.hIcon = hIcon;
	wnd.lpszClassName = TEXT("heboserver");
	RegisterClass(&wnd);
	
	CreateWindow(TEXT("heboserver"), TEXT("heboserver Listener Window"), 0, 0, 0, 0, 0, NULL, NULL, hinst, NULL);
}

// コマンドラインオプション解析
void CommandLineOptions(const char *lpszCmdLine) {
	char cmdline[256];
	char *strPort, *strMaxClients;
	
	strncpy(cmdline, lpszCmdLine, 256);
	cmdline[255] = '\0';
	
	strPort = strtok(cmdline, " ");
	strMaxClients = strtok(NULL, " ");
	
	if(strPort != NULL) server_port = atoi(strPort);
	if(strMaxClients != NULL) server_maxclients = atoi(strMaxClients);
	
	if(server_port > 65535) server_port = 65535;
	if(server_port < 1) server_port = 1;
	if(server_maxclients > MAX_CLIENTS) server_maxclients = MAX_CLIENTS;
	if(server_maxclients < 1) server_maxclients = 1;
}

// メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	MSG msg;
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	server_port = DEFAULT_PORT;
	server_maxclients = DEFAULT_MAX_CLIENTS;
	
	if(strlen(lpszCmdLine) > 0) CommandLineOptions(lpszCmdLine);
	
	CreateListenerWindow(GetModuleHandle(NULL));
	
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	WSACleanup();
	
	return 0;
}
