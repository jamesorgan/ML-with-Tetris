#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resource.h"
#include "heboplugin.h"

HINSTANCE hInst;
char basedir[BUF_SIZE];
char filedlgdir[BUF_SIZE];

int cmdenable;
char cmdline[BUF_SIZE];

// �v���O�C���ꗗ��ǂݍ���
int loadPluginList(HWND hListbox) {
	FILE *fp;
	char text[BUF_SIZE];
	char tmpstr[BUF_SIZE];
	char *tok1, *tok2;
	int count;
	
	// �t�@�C�����J��
	fp = fopen(PLUGIN_LIST_FILE_NAME, "r");
	if(!fp) return 0;
	
	// �ǂݍ���
	count = 0;
	while(fgets(text, BUF_SIZE, fp) != NULL) {
		// ""�ň͂܂ꂽ�Ƃ�������o��
		tok1 = strchr(text, '\"');
		
		if(tok1 != NULL) {
			tok2 = strchr(tok1 + 1, '\"');
			
			if(tok2 != NULL) {
				ZeroMemory(&tmpstr, BUF_SIZE);
				strncpy(tmpstr, tok1 + 1, tok2 - tok1 - 1);
				SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)tmpstr);
				count++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	if(count > 0) SendMessage(hListbox, LB_SETCURSEL, 0, 0);
	fclose(fp);
	
	return count;
}

// �v���O�C�����X�g��ۑ�
void savePluginList(HWND hListbox) {
	int i;
	int max;
	FILE *fp;
	char filename[BUF_SIZE];
	char prefix[BUF_SIZE];
	BYTE *isvalid;	// �������v���O�C�����ǂ����̃t���O
	
	// �f�B���N�g�����N�����̕��ɖ߂�
	SetCurrentDirectory(basedir);
	
	// �t�@�C�����쐬
	fp = fopen(PLUGIN_LIST_FILE_NAME, "w");
	if(!fp) return;
	
	// ���X�g�{�b�N�X���̍��ڂ̐����擾
	max = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
	isvalid = (BYTE*)malloc(max);
	
	// �t�@�C���ɏ����o��
	for(i = 0; i < max; i++) {
		SendMessage(hListbox, LB_GETTEXT, i, (LPARAM)filename);
		isvalid[i] = loadPluginFile(filename, NULL);
		
		if(isvalid[i]) fprintf(fp, "include \"%s\"\n", filename);
	}
	
	fprintf(fp, "\nvoid executePlugin(int player, int event, int *param) {\n");
	for(i = 0; i < max; i++) {
		if(isvalid[i]) {
			SendMessage(hListbox, LB_GETTEXT, i, (LPARAM)filename);
			loadPluginFile(filename, prefix);
			fprintf(fp, "\t%sPluginEvent(player, event, param);\n", prefix);
		}
	}
	fprintf(fp, "}\n");
	
	free(isvalid);
	fclose(fp);
}

// ���ёւ�
void movePluginList(HWND hListbox, int mode) {
	int current, max;
	char filename[BUF_SIZE];
	
	// ���ݑI�����Ă��鍀�ڂ̈ʒu���擾
	current = SendMessage(hListbox, LB_GETCURSEL, 0, 0);
	if(current == LB_ERR) return;
	
	// ���ڂ̍��v�����擾
	max = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
	if(max == LB_ERR) return;
	
	// �[�����̍��ڂ𓮂������Ƃ��Ă�����߂�
	if((mode == -1) && (current == 0)) return;
	if((mode == 1) && (current == max - 1)) return;
	
	// ���ݑI�����Ă��鍀�ڂ��o�b�t�@�ɃR�s�[
	SendMessage(hListbox, LB_GETTEXT, current, (LPARAM)filename);
	
	// �폜
	SendMessage(hListbox, LB_DELETESTRING, current, 0);
	
	// ���ڂ�1�ォ���ɕ���
	SendMessage(hListbox, LB_INSERTSTRING, current + mode, (LPARAM)filename);
	
	// �I��
	SendMessage(hListbox, LB_SETCURSEL, current + mode, 0);
}

// �v���O�C���t�@�C����������������^�v���O�C���t�@�C����ǂݍ���Ńv���t�B�b�N�X���擾
int loadPluginFile(char *filename, char *prefix) {
	int i;
	FILE *fp;
	char text[BUF_SIZE];
	char *ptr;
	
	fp = fopen(filename, "r");
	if(!fp) return 0;
	
	while(fgets(text, BUF_SIZE, fp) != NULL) {
		ptr = strstr(text, "//prefix:");
		
		if(ptr != NULL) {
			if(prefix != NULL) {
				// �o�b�t�@�ɃR�s�[
				strcpy(prefix, ptr + 9);
				
				// ���s�L����NULL�����ɕς���
				i = 0;
				while(prefix[i] != 0) i++;
				prefix[i - 1] = 0;
			}
			fclose(fp);
			return 1;
		}
	}
	
	fclose(fp);
	return 0;
}

// �t�@�C���p�X�̉~�L�����X���b�V���L���ɕς���
void convertYenToSlash(char *filename) {
	int i;
	i = 0;
	
	while(filename[i] != '\0') {
		if(filename[i] == '\\') filename[i] = '/';
		i++;
	}
}

// ��΃p�X�𑊑΃p�X�ɕς���
void convertFullPathToShort(char *basename, char *filename) {
	char str[BUF_SIZE];
	strncpy(str, filename, sizeof(str));
	PathRelativePathTo(filename, basename, FILE_ATTRIBUTE_DIRECTORY, str, FILE_ATTRIBUTE_NORMAL);
}

// �t�@�C�����J���_�C�A���O��\��
BOOL OpenFileDialog(HWND hwnd, char *filename) {
	OPENFILENAME ofn;
	
	ZeroMemory(&ofn, sizeof(ofn));
	ZeroMemory(filename, FILENAME_BUF_SIZE);
	
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = OPENDIALOG_FILTER;
	ofn.lpstrFile = filename;
	ofn.lpstrInitialDir = filedlgdir;
	ofn.nMaxFile = FILENAME_BUF_SIZE;
	ofn.Flags = OFN_ALLOWMULTISELECT | OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	
	return GetOpenFileName(&ofn);
}

// �t�@�C�����J���_�C�A���O���őI�������t�@�C�����𐔂���
int countFileNameString(char *filename) {
	int i, count;
	i = 0;
	count = 0;
	
	while(1) {
		if((filename[i] == '\0') && (filename[i + 1] == '\0')) {
			break;
		} else if(filename[i] == '\0') {
			count++;
		}
		
		i++;
	}
	
	return count;
}

// �t�@�C�����J���_�C�A���O���őI�������t�@�C�����ւ̃I�t�Z�b�g��Ԃ�
int getFileNameString(char *filename, int number) {
	int i, count;
	i = 0;
	count = 0;
	
	while(1) {
		if((filename[i] == '\0') && (filename[i + 1] == '\0')) {
			break;
		} else if(filename[i] == '\0') {
			count++;
		}
		
		i++;
		if(count >= number) break;
	}
	
	return i;
}

// �^�C�g���o�[���X�V
void updateTitleBar(HWND hwndDlg, HWND hListbox) {
	int max;
	char buf[256];
	
	max = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
	sprintf(buf, VERSION_STR, max);
	SetWindowText(hwndDlg, buf);
}

// ���C���_�C�A���O�̏���
BOOL CALLBACK MainDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	int i;
	int cur;
	int temp, temp2;
	char filename[FILENAME_BUF_SIZE];
	char tempname[BUF_SIZE];
	char pluginname[BUF_SIZE];
	HWND hListbox;
	HICON hIcon;
	
	switch(uMsg) {
		// ������
		case WM_INITDIALOG:
			// �A�C�R����ݒ�
			hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
			SendMessage(hwndDlg, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
			hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
			SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
			
			// �v���O�C���ꗗ��ǂݍ���
			hListbox = GetDlgItem(hwndDlg, IDC_LIST_PLUGIN);
			loadPluginList(hListbox);
			
			// �R�}���h���C������ǉ�
			if(cmdenable) {
				// �V�������ڂ�ǉ�
				convertFullPathToShort(basedir, cmdline);
				convertYenToSlash(cmdline);
				SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)cmdline);
				
				// �J�[�\�������킹��
				cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
				SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
			}
			
			updateTitleBar(hwndDlg, hListbox);
			return 1;
		// �{�^���N���b�N
		case WM_COMMAND:
			hListbox = GetDlgItem(hwndDlg, IDC_LIST_PLUGIN);
			
			switch(LOWORD(wParam)) {
				case IDC_BUTTON_ADD:
					// �ǉ�
					if(OpenFileDialog(hwndDlg, filename)) {
						// �t�@�C�����𐔂���
						temp = countFileNameString(filename);
						
						// ���ʂ�0�i�������I�����Ă��Ȃ��j�ꍇ
						if(temp == 0) {
							// �p�X��Z������
							convertFullPathToShort(basedir, filename);
							convertYenToSlash(filename);
							
							// �d���`�F�b�N
							temp2 = SendMessage(hListbox, LB_FINDSTRING, -1, (LPARAM)filename);
							
							if(temp2 == LB_ERR) {
								// �V�������ڂ�ǉ�
								SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)filename);
								
								// �J�[�\�������킹��
								cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
								SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
							} else {
								// ���ɂ�����ɃJ�[�\�������킹��
								SendMessage(hListbox, LB_SETCURSEL, temp2, 0);
							}
						}
						// �����I�����Ă���ꍇ
						else {
							for(i = 0; i < temp; i++) {
								// �t�@�C���p�X�����߂�
								strcpy(pluginname, filename);
								strcpy(tempname, filename + getFileNameString(filename, i + 1));
								PathAppend(pluginname, tempname);
								
								// �p�X��Z������
								convertFullPathToShort(basedir, pluginname);
								convertYenToSlash(pluginname);
								
								// �d���`�F�b�N
								temp2 = SendMessage(hListbox, LB_FINDSTRING, -1, (LPARAM)pluginname);
								
								if(temp2 == LB_ERR) {
									// ���ڒǉ�
									SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)pluginname);
									
									// �J�[�\�������킹��
									cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
									SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
								} else {
									// ���ɂ�����ɃJ�[�\�������킹��
									SendMessage(hListbox, LB_SETCURSEL, temp2, 0);
								}
							}
						}
						
						// �^�C�g���o�[�X�V
						updateTitleBar(hwndDlg, hListbox);
					}
					return 1;
				case IDC_BUTTON_REMOVE:
					// �폜
					cur = SendMessage(hListbox, LB_GETCURSEL, 0, 0);
					if(cur != LB_ERR) {
						SendMessage(hListbox, LB_DELETESTRING, cur, 0);
						temp = SendMessage(hListbox, LB_SETCURSEL, cur, 0);
						if(temp == LB_ERR) SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
					}
					updateTitleBar(hwndDlg, hListbox);
					return 1;
				case IDC_BUTTON_UP:
					// ��Ɉړ�
					movePluginList(hListbox, -1);
					return 1;
				case IDC_BUTTON_DOWN:
					// ���Ɉړ�
					movePluginList(hListbox, 1);
					return 1;
				case IDC_BUTTON_OK:
					// OK
					savePluginList(hListbox);
					EndDialog(hwndDlg, 1);
					return 1;
				case IDCANCEL:
					// �L�����Z��
					EndDialog(hwndDlg, 0);
					return 1;
			}
			break;
		// �h���b�O���h���b�v
		case WM_DROPFILES:
			hListbox = GetDlgItem(hwndDlg, IDC_LIST_PLUGIN);
			
			// �h���b�v���ꂽ�t�@�C�������擾
			temp = DragQueryFile((HDROP)wParam, 0xFFFFFFFF, NULL, 0);
			
			for(i = 0; i < temp; i++) {
				// �t�@�C�������擾
				DragQueryFile((HDROP)wParam, i, filename, sizeof(filename));
				
				// �t�@�C������Z������
				convertFullPathToShort(basedir, filename);
				convertYenToSlash(filename);
				
				// �d���`�F�b�N
				temp2 = SendMessage(hListbox, LB_FINDSTRING, -1, (LPARAM)filename);
				
				if(temp2 == LB_ERR) {
					// ���ڒǉ�
					SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)filename);
					
					// �J�[�\�������킹��
					cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
					SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
				} else {
					// ���ɂ�����ɃJ�[�\�������킹��
					SendMessage(hListbox, LB_SETCURSEL, temp2, 0);
				}
			}
			
			DragFinish((HDROP)wParam);
			
			// �^�C�g���o�[�X�V
			updateTitleBar(hwndDlg, hListbox);
			
			return 1;
		// �I��
		case WM_CLOSE:
			EndDialog(hwndDlg, 0);
			return 1;
	}
	
	return 0;
}

// �v���O�����J�n���ɌĂ΂�郁�C���֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	// �J�����g�f�B���N�g����heboplugin.exe������ꏊ�ɂ���
	GetModuleFileName(NULL, basedir, BUF_SIZE);
	PathRemoveFileSpec(basedir);
	SetCurrentDirectory(basedir);
	strncpy(filedlgdir, basedir, BUF_SIZE);
	
	// �R�}���h���C���I�v�V����
	cmdenable = 0;
	if(strlen(lpszCmdLine) > 0) {
		strncpy(cmdline, lpszCmdLine, BUF_SIZE);
		cmdenable = 1;
	}
	
	// �_�C�A���O�\��
	hInst = hInstance;
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDialogProc);
	
	return 0;
}
