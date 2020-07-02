#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <shellapi.h>
#include "resource.h"

#define MAX_CLIENTS 512						// �R�}���h���C���Ŏw��ł���ő�ڑ���(Max clients can be set in command line)
#define DEFAULT_MAX_CLIENTS 256				// �f�t�H���g�̍ő�ڑ���(Default max clients)
#define DEFAULT_PORT 5000					// �f�t�H���g�Ŏg���|�[�g(Default port)

#define MAX_BUFFER 65536					// ��M�^���M�p�o�b�t�@�̑傫��
#define SERVER_VERSION 2					// �T�[�o�[�o�[�W����

WSADATA wsaData;							// Winsock�̃o�[�W�����Ɋւ���f�[�^

SOCKET sockets[MAX_CLIENTS + 1];			// �\�P�b�g
struct sockaddr_in addr[MAX_CLIENTS + 1];	// IP�A�h���X�A�|�[�g�ԍ����i�[
int client_count;							// �N���C�A���g�ڑ���
int server_port;							// �T�[�o�[�̃|�[�g�ԍ�
int server_maxclients;						// �ő�ڑ���

int client_status[MAX_CLIENTS + 1];			// �N���C�A���g�̏�ԁi0=���j���[��� 1=����҂� 2=�v���C���j
int client_engineversion[MAX_CLIENTS + 1];	// �N���C�A���g���g���Ă���Q�[���̃G���W���̃o�[�W����
int client_modeversion[MAX_CLIENTS + 1];	// �N���C�A���g���g���Ă��郂�[�h�̃o�[�W����
char client_gamemode[MAX_CLIENTS + 1][32];	// �N���C�A���g���g���Ă��郂�[�h�̖��O

long buf_in[MAX_BUFFER];					// ��M�p�o�b�t�@
long buf_out[MAX_BUFFER];					// ���M�p�o�b�t�@

HICON hIcon;								// �A�C�R��
NOTIFYICONDATA nIconData;					// �g���C�A�C�R���̍\����
UINT mTaskbarCreated;						// �g���C�A�C�R���ēo�^�C�x���g�̃��b�Z�[�W�ԍ�

// ��M�\�o�C�g���𒲂ׂ�
unsigned long ReceiveLength(SOCKET sock) {
	unsigned long result;
	result = 0;
	ioctlsocket(sock, FIONREAD, &result);
	return result;
}

// ������
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

// �\�P�b�g�̔ԍ��𒲂ׂ�
// ���m�̃\�P�b�g�Ȃ�-1�ɂȂ�
int IdentifySocketID(SOCKET sock) {
	int i;
	
	for(i = 0; i < server_maxclients + 1; i++) {
		if(sock == sockets[i]) {
			return i;
		}
	}
	
	return -1;
}

// �J���Ă���\�P�b�g�̔ԍ���Ԃ�
int SearchEmptySocketID() {
	int i;
	
	for(i = 0; i < server_maxclients + 1; i++) {
		if(sockets[i] == INVALID_SOCKET) {
			return i;
		}
	}
	
	return -1;
}

// �����҂��Ă���v���C���[��T���i�����Ɠ������[�h�ƃo�[�W�����̃v���C���[�̂݁j
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

// �����Ɠ������[�h�ƃo�[�W�����̃v���C���[���𐔂���
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

// �҂��󂯊J�n
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

// �ڑ��v�����󂯓����
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
		
		// �S�v���C���[�ɒʒm
		for(i = 1; i < server_maxclients + 1; i++) {
			if((sockets[i] != INVALID_SOCKET) && (i != id)) {
				size = 5 * 4;
				buf_out[0] = size;				// �T�C�Y
				buf_out[1] = 0;					// ���M��
				buf_out[2] = 1;					// �R�}���h
				buf_out[3] = id;				// ID
				buf_out[4] = client_count;		// �ڑ��l��
				send(sockets[i], (char *)buf_out, size, 0);
			}
		}
	}
}

// �ڑ����ؒf���ꂽ�Ƃ�
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
		
		// �S�v���C���[�ɒʒm
		for(i = 1; i < server_maxclients + 1; i++) {
			if(sockets[i] != INVALID_SOCKET) {
				size = 5 * 4;
				buf_out[0] = size;				// �T�C�Y
				buf_out[1] = 0;					// ���M��
				buf_out[2] = 2;					// �R�}���h
				buf_out[3] = id;				// ID
				buf_out[4] = client_count;		// �ڑ��l��
				send(sockets[i], (char *)buf_out, size, 0);
			}
		}
	}
}

// �f�[�^��M
void ReceiveDataFromClient(SOCKET sock, LONG error) {
	int i;
	int temp;
	int command, id_from, id_to;
	int result;
	int size;
	
	// �ŏ���4�o�C�g��������M�i�T�C�Y�𒲂ׂ�j
	// �i�܂��L���[���珜���͂��Ȃ��j
	result = recv(sock, (char *)buf_in, 4, MSG_PEEK);
	if(result == SOCKET_ERROR) return;
	
	// �ǂݍ��ރT�C�Y�����߂�
	size = buf_in[0];
	if(size < 1) return;
	
	// �f�[�^���S�ė��Ă��邩�ǂ����m�F
	// (TODO: Add Mr.DeHackEd's new, excellent buffering system)
	if(ReceiveLength(sock) < size) return;
	
	// �c��̃f�[�^��ǂݍ���
	result = recv(sock, (char *)buf_in, size, 0);
	if(result == SOCKET_ERROR) return;
	
	// ���M��ID�𔻒�
	id_from = IdentifySocketID(sock);
	if(id_from == -1) return;
	
	// ��M�����f�[�^�ɉ����ď������s��
	id_to = buf_in[1];
	command = buf_in[2];
	
	// ���M��ID��0�i�T�[�o�[�j��������
	if(id_to == 0) {
		switch(command) {
			case 0:	// ���擾
				size = 8 * 4;
				buf_out[0] = size;						// �T�C�Y
				buf_out[1] = 0;							// ���M��
				buf_out[2] = 0;							// �R�}���h
				buf_out[3] = SERVER_VERSION;			// �o�[�W����
				buf_out[4] = client_count;				// �ڑ��l��
				buf_out[5] = id_from;					// ������ID
				buf_out[6] = client_status[id_from];	// �����̏��
				buf_out[7] = server_maxclients;			// �ő�ڑ��l��
				send(sock, (char *)buf_out, size, 0);
				break;
			case 1:	// �o�[�W�����ݒ�
				client_engineversion[id_from] = buf_in[3];
				client_modeversion[id_from] = buf_in[4];
				strncpy(client_gamemode[id_from], (char *)buf_in + (5 * 4), 32);
				break;
			case 2:	// �����̏�Ԃ�ς���
				client_status[id_from] = buf_in[3];
				break;
			case 3:	// �ΐ푊���T��
				temp = SearchWaitingPlayer(id_from);
				if(temp != -1) {
					// ���肪��������
					size = 4 * 4;
					buf_out[0] = size;					// �T�C�Y
					buf_out[1] = 0;						// ���M��
					buf_out[2] = 3;						// �R�}���h
					buf_out[3] = temp;					// �����ID
					send(sock, (char *)buf_out, size, 0);
				} else {
					// ������Ȃ�
					size = 3 * 4;
					buf_out[0] = size;					// �T�C�Y
					buf_out[1] = 0;						// ���M��
					buf_out[2] = 4;						// �R�}���h
					send(sock, (char *)buf_out, size, 0);
				}
				break;
			case 4:	// �����Ɠ������[�h�ƃo�[�W�����̃v���C���[�����擾
				size = 6 * 4;
				buf_out[0] = size;		// �T�C�Y
				buf_out[1] = 0;			// ���M��
				buf_out[2] = 5;			// �R�}���h
				buf_out[3] = CountSameModeAndVersionPlayer(id_from, 0);	// ���j���[��ʂ̃v���C���[��
				buf_out[4] = CountSameModeAndVersionPlayer(id_from, 1);	// ����҂��̃v���C���[��
				buf_out[5] = CountSameModeAndVersionPlayer(id_from, 2);	// �v���C���̃v���C���[��
				send(sock, (char *)buf_out, size, 0);
				break;
		}
	}
	// ���M��ID��1�ȏ�i���̃v���C���[�j��������
	else if((id_to < server_maxclients + 1) && (sockets[id_to] != INVALID_SOCKET) && 
	        (strcmp(client_gamemode[id_from], client_gamemode[id_to]) == 0) && 
	        (client_modeversion[id_from] == client_modeversion[id_to]) && (client_engineversion[id_from] == client_engineversion[id_to]))
	{
		for(i = 0; i < (size / 4); i++) buf_out[i] = buf_in[i];
		buf_out[1] = id_from;	// ���M��
		send(sockets[id_to], (char *)buf_out, size, 0);
	}
}

// �^�X�N�g���C�ɃA�C�R����o�^
BOOL AddTrayIcon(HWND hwnd) {
	char tip[64];
	
	// �\���̂�ݒ�
	ZeroMemory(&nIconData, sizeof(nIconData));
	nIconData.cbSize = sizeof(nIconData);
	nIconData.hWnd = hwnd;
	nIconData.uID = 0;
	nIconData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	nIconData.uCallbackMessage = WM_USER + 1;
	nIconData.hIcon = hIcon;
	sprintf(tip, "heboserver (%d,%d)", server_port, server_maxclients);
	strcpy(nIconData.szTip, tip);
	
	// �A�C�R����o�^
	while(1) {
		if(Shell_NotifyIcon(NIM_ADD, &nIconData)) {
			// �o�^����
			return TRUE;
		} else {
			// �����ҋ@
			Sleep(1000);
			
			if(Shell_NotifyIcon(NIM_MODIFY, &nIconData)) {
				// �o�^���������Ă���
				return TRUE;
			}
		}
	}
}

// �T�[�o�[�̏���\��
void DisplayServerInfo() {
	char strMsg[256];
	sprintf(strMsg, "Version:%d\nPort:%d\nMax Clients:%d", SERVER_VERSION, server_port, server_maxclients);
	MessageBox(NULL, strMsg, TEXT("heboserver"), MB_OK | MB_SETFOREGROUND);
}

// �C�x���g�����p�E�B���h�E�̏���
LRESULT CALLBACK ListenerWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch(uMsg) {
		case WM_CREATE:	// ������
			mTaskbarCreated = RegisterWindowMessage(TEXT("TaskbarCreated"));	// Explorer���A���b�Z�[�WID�𒲂ׂ�
			AddTrayIcon(hwnd);	// �^�X�N�g���C�ɃA�C�R����o�^
			StartServerListen(hwnd);
			break;
		case WM_USER:	// �\�P�b�g�C�x���g
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
		case WM_USER + 1:	// �g���C�A�C�R���̃C�x���g
			switch(lParam) {
				case WM_LBUTTONUP:	// ���N���b�N
					DisplayServerInfo();
					break;
				case WM_RBUTTONUP:	// �E�N���b�N
					if(MessageBox(NULL, TEXT("Quit?"), TEXT("heboserver"), MB_OKCANCEL | MB_SETFOREGROUND) == IDOK) {
						SendMessage(hwnd, WM_CLOSE, 0, 0);
					}
					break;
			}
			break;
		case WM_DESTROY:	// �I��
			Shell_NotifyIcon(NIM_DELETE, &nIconData);	// �^�X�N�g���C�A�C�R��������
			PostQuitMessage(0);
			return 0;
		default:	// ���̑�
			// Explorer�N���b�V����̃g���C�A�C�R������
			if(uMsg == mTaskbarCreated) AddTrayIcon(hwnd);
			break;
	}
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// �C�x���g�����p�E�B���h�E���쐬
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

// �R�}���h���C���I�v�V�������
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

// ���C���֐�
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
