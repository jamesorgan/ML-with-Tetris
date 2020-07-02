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

WSADATA wsaData;				// Winsock�̃o�[�W�����Ɋւ���f�[�^
SOCKET sock;					// �\�P�b�g
struct sockaddr_in server;		// �ڑ���Ɋւ���f�[�^

HWND listener_hwnd;				// �C�x���g�����p�E�B���h�E�̃n���h��

BOOL isConnect;					// �ڑ�������TRUE�ɂȂ�
BOOL isWriteReady;				// �f�[�^�̑��M�o�b�t�@����Ȃ�TRUE�ɂȂ�
BOOL isReadReady;				// �V�����f�[�^����M�ł���Ȃ�TRUE�ɂȂ�
BOOL isErrorEvent;				// �G���[�C�x���g�����Ȃ�TRUE�ɂȂ�

// �C�x���g�����p�E�B���h�E�̏���
LRESULT CALLBACK ListenerWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg) {
		case WM_CREATE:	// ������
			isConnect = FALSE;
			isWriteReady = FALSE;
			isReadReady = FALSE;
			isErrorEvent = FALSE;
			break;
		case WM_USER:	// �\�P�b�g�C�x���g
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

// �C�x���g�����p�E�B���h�E���쐬
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

// winsock�̏�����
// tcpStartup();
TUserFunc(tcpStartup)
{
	CreateListenerWindow(GetModuleHandle(NULL));
	return WSAStartup(MAKEWORD(2,0), &wsaData);
}

// winsock�̏I��
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

// �\�P�b�g�̍쐬
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

// �ڑ�
// tcpConnect("�z�X�g��", �|�[�g);
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

// �ؒf
// tcpClosesocket();
TUserFunc(tcpClosesocket)
{
	isConnect = FALSE;
	return closesocket(sock);
}

// ��M
// tcpRecv(�]����A�h���X,�T�C�Y);
TUserFunc(tcpRecv)
{
	isReadReady = FALSE;
	return recv(sock, (char *)*p, (int)*(p+1), 0);
}

// ��M�i��M�L���[����͎�菜���Ȃ��j
// tcpRecvPeek(�]����A�h���X,�T�C�Y);
TUserFunc(tcpRecvPeek)
{
	return recv(sock, (char *)*p, (int)*(p+1), MSG_PEEK);
}

// ���M
// tcpSend(�]�����A�h���X,�T�C�Y);
TUserFunc(tcpSend)
{
	isWriteReady = FALSE;
	return send(sock, (const char *)*p, (int)*(p+1), 0);
}

// �G���[�R�[�h���擾
// tcpWSAGetLastError();
TUserFunc(tcpWSAGetLastError)
{
	return WSAGetLastError();
}

// �ڑ����Ă���Ȃ�0�ȊO�̒l��Ԃ�
// tcpIsConnect();
TUserFunc(tcpIsConnect)
{
	return isConnect;
}

// �V�����f�[�^����M�ł���Ȃ�0�ȊO�̒l��Ԃ�
// tcpIsReadReady();
TUserFunc(tcpIsReadReady)
{
	return isReadReady;
}

// �f�[�^�̑��M�o�b�t�@����Ȃ�0�ȊO�̒l��Ԃ�
// tcpIsWriteReady();
TUserFunc(tcpIsWriteReady)
{
	return isWriteReady;
}

// ���炩�̃G���[�C�x���g����������0�ȊO�̒l��Ԃ�
// tcpIsErrorEvent();
TUserFunc(tcpIsErrorEvent)
{
	return isErrorEvent;
}

// ��M�ł���o�C�g����Ԃ�
TUserFunc(tcpReceiveLength)
{
	unsigned long result;
	result = 0;
	ioctlsocket(sock, FIONREAD, &result);
	return result;
}

// �����ɁA����DLL�Ŏg���Ă���֐���񋓂���
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
