#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>

#ifdef __cplusplus
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

#define TUserFunc(FUNC) EXPORT LONG FUNC(LONG *p)

typedef struct {
	LPSTR		lpFuncName;
	LONG		(*lpFunc)(LONG*);
} SDllTable;

WSADATA wsaData;				// Winsockのバージョンに関するデータ
SOCKET sock;					// ソケット
struct sockaddr_in server;		// 接続先に関するデータ

HWND listener_hwnd;				// イベント処理用ウィンドウのハンドル

BOOL isConnect;					// 接続したらTRUEになる
BOOL isWriteReady;				// データの送信バッファが空ならTRUEになる
BOOL isReadReady;				// 新しいデータを受信できるならTRUEになる
BOOL isErrorEvent;				// エラーイベント発生ならTRUEになる

// イベント処理用ウィンドウの処理
LRESULT CALLBACK ListenerWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg) {
		case WM_CREATE:	// 初期化
			isConnect = FALSE;
			isWriteReady = FALSE;
			isReadReady = FALSE;
			isErrorEvent = FALSE;
			break;
		case WM_USER:	// ソケットイベント
			if(WSAGETSELECTERROR(lParam) != 0) {
				isErrorEvent = TRUE;
			} else {
				isErrorEvent = FALSE;
			}
			
			switch(WSAGETSELECTEVENT(lParam)) {
				case FD_CONNECT:
					isConnect = TRUE;
					break;
				case FD_WRITE:
					isWriteReady = TRUE;
					break;
				case FD_READ:
					isReadReady = TRUE;
					break;
				case FD_CLOSE:
					isConnect = FALSE;
					break;
			}
			
			break;
	}
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// イベント処理用ウィンドウを作成
void CreateListenerWindow(HINSTANCE hinst)
{
	WNDCLASS wnd;
	
	ZeroMemory(&wnd, sizeof(wnd));
	wnd.style = CS_NOCLOSE;
	wnd.lpfnWndProc = ListenerWindowProc;
	wnd.hInstance = hinst;
	wnd.lpszClassName = TEXT("ygs2kTCP");
	RegisterClass(&wnd);
	
	listener_hwnd = CreateWindow(TEXT("ygs2kTCP"), TEXT("ygs2kTCP Listener Window"), 0, 0, 0, 0, 0, NULL, NULL, hinst, NULL);
}

// winsockの初期化
// tcpStartup();
TUserFunc(tcpStartup)
{
	CreateListenerWindow(GetModuleHandle(NULL));
	return WSAStartup(MAKEWORD(2,0), &wsaData);
}

// winsockの終了
// tcpCleanup();
TUserFunc(tcpCleanup)
{
	DestroyWindow(listener_hwnd);
	if(isConnect) {
		closesocket(sock);
		isConnect = FALSE;
	}
	isWriteReady = FALSE;
	isReadReady = FALSE;
	return WSACleanup();
}

// ソケットの作成
// tcpSocket();
TUserFunc(tcpSocket)
{
	BOOL opt = TRUE;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET) {
		return -1;
	}
	
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&opt, sizeof(opt));
	
	if(WSAAsyncSelect(sock, listener_hwnd, WM_USER, FD_CONNECT | FD_WRITE | FD_READ | FD_CLOSE) != 0) {
		return -2;
	}
	
	return 0;
}

// 接続
// tcpConnect("ホスト名", ポート);
TUserFunc(tcpConnect)
{
	char *hostname = (char *)*p;
	long port = *(p+1);
	
	struct hostent *host;
	unsigned int **addrptr;
	
	isConnect = FALSE;
	isWriteReady = FALSE;
	isReadReady = FALSE;
	isErrorEvent = FALSE;
	
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	
	server.sin_addr.S_un.S_addr = inet_addr(hostname);
	
	if(server.sin_addr.S_un.S_addr == 0xffffffff) {
		host = gethostbyname(hostname);
		if(host == NULL) return -1;
		
		addrptr = (unsigned int **)host->h_addr_list;
		
		while(*addrptr != NULL) {
			server.sin_addr.S_un.S_addr = *(*addrptr);
			
			if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
				break;
			}
			
			addrptr++;
		}
		
		return -2;
	} else {
		if(connect(sock, (struct sockaddr *)&server, sizeof(server)) != 0) {
			return -2;
		}
	}
	
	return 0;
}

// 切断
// tcpClosesocket();
TUserFunc(tcpClosesocket)
{
	isConnect = FALSE;
	return closesocket(sock);
}

// 受信
// tcpRecv(転送先アドレス,サイズ);
TUserFunc(tcpRecv)
{
	isReadReady = FALSE;
	return recv(sock, (char *)*p, (int)*(p+1), 0);
}

// 受信（受信キューからは取り除かない）
// tcpRecvPeek(転送先アドレス,サイズ);
TUserFunc(tcpRecvPeek)
{
	return recv(sock, (char *)*p, (int)*(p+1), MSG_PEEK);
}

// 送信
// tcpSend(転送元アドレス,サイズ);
TUserFunc(tcpSend)
{
	isWriteReady = FALSE;
	return send(sock, (const char *)*p, (int)*(p+1), 0);
}

// エラーコードを取得
// tcpWSAGetLastError();
TUserFunc(tcpWSAGetLastError)
{
	return WSAGetLastError();
}

// 接続しているなら0以外の値を返す
// tcpIsConnect();
TUserFunc(tcpIsConnect)
{
	return isConnect;
}

// 新しいデータを受信できるなら0以外の値を返す
// tcpIsReadReady();
TUserFunc(tcpIsReadReady)
{
	return isReadReady;
}

// データの送信バッファが空なら0以外の値を返す
// tcpIsWriteReady();
TUserFunc(tcpIsWriteReady)
{
	return isWriteReady;
}

// 何らかのエラーイベントがあったら0以外の値を返す
// tcpIsErrorEvent();
TUserFunc(tcpIsErrorEvent)
{
	return isErrorEvent;
}

// 受信できるバイト数を返す
TUserFunc(tcpReceiveLength)
{
	unsigned long result;
	result = 0;
	ioctlsocket(sock, FIONREAD, &result);
	return result;
}

// ここに、このDLLで使っている関数を列挙する
EXPORT SDllTable* InquireFunction(void)
{
	static SDllTable S[] = {
		{"tcpStartup",tcpStartup},
		{"tcpCleanup",tcpCleanup},
		{"tcpSocket",tcpSocket},
		{"tcpConnect",tcpConnect},
		{"tcpClosesocket",tcpClosesocket},
		{"tcpRecv",tcpRecv},
		{"tcpRecvPeek",tcpRecvPeek},
		{"tcpSend",tcpSend},
		{"tcpWSAGetLastError",tcpWSAGetLastError},
		{"tcpIsConnect",tcpIsConnect},
		{"tcpIsReadReady",tcpIsReadReady},
		{"tcpIsWriteReady",tcpIsWriteReady},
		{"tcpIsErrorEvent",tcpIsErrorEvent},
		{"tcpReceiveLength",tcpReceiveLength},
		{NULL,NULL}
	};
	return &S[0];
}
