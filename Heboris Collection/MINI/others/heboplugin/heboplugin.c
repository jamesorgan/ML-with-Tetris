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

// プラグイン一覧を読み込み
int loadPluginList(HWND hListbox) {
	FILE *fp;
	char text[BUF_SIZE];
	char tmpstr[BUF_SIZE];
	char *tok1, *tok2;
	int count;
	
	// ファイルを開く
	fp = fopen(PLUGIN_LIST_FILE_NAME, "r");
	if(!fp) return 0;
	
	// 読み込み
	count = 0;
	while(fgets(text, BUF_SIZE, fp) != NULL) {
		// ""で囲まれたところを取り出す
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

// プラグインリストを保存
void savePluginList(HWND hListbox) {
	int i;
	int max;
	FILE *fp;
	char filename[BUF_SIZE];
	char prefix[BUF_SIZE];
	BYTE *isvalid;	// 正しいプラグインかどうかのフラグ
	
	// ディレクトリを起動時の物に戻す
	SetCurrentDirectory(basedir);
	
	// ファイルを作成
	fp = fopen(PLUGIN_LIST_FILE_NAME, "w");
	if(!fp) return;
	
	// リストボックス内の項目の数を取得
	max = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
	isvalid = (BYTE*)malloc(max);
	
	// ファイルに書き出し
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

// 並び替え
void movePluginList(HWND hListbox, int mode) {
	int current, max;
	char filename[BUF_SIZE];
	
	// 現在選択している項目の位置を取得
	current = SendMessage(hListbox, LB_GETCURSEL, 0, 0);
	if(current == LB_ERR) return;
	
	// 項目の合計数を取得
	max = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
	if(max == LB_ERR) return;
	
	// 端っこの項目を動かそうとしていたら戻る
	if((mode == -1) && (current == 0)) return;
	if((mode == 1) && (current == max - 1)) return;
	
	// 現在選択している項目をバッファにコピー
	SendMessage(hListbox, LB_GETTEXT, current, (LPARAM)filename);
	
	// 削除
	SendMessage(hListbox, LB_DELETESTRING, current, 0);
	
	// 項目を1つ上か下に複製
	SendMessage(hListbox, LB_INSERTSTRING, current + mode, (LPARAM)filename);
	
	// 選択
	SendMessage(hListbox, LB_SETCURSEL, current + mode, 0);
}

// プラグインファイルが正しいか判定／プラグインファイルを読み込んでプレフィックスを取得
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
				// バッファにコピー
				strcpy(prefix, ptr + 9);
				
				// 改行記号をNULL文字に変える
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

// ファイルパスの円記号をスラッシュ記号に変える
void convertYenToSlash(char *filename) {
	int i;
	i = 0;
	
	while(filename[i] != '\0') {
		if(filename[i] == '\\') filename[i] = '/';
		i++;
	}
}

// 絶対パスを相対パスに変える
void convertFullPathToShort(char *basename, char *filename) {
	char str[BUF_SIZE];
	strncpy(str, filename, sizeof(str));
	PathRelativePathTo(filename, basename, FILE_ATTRIBUTE_DIRECTORY, str, FILE_ATTRIBUTE_NORMAL);
}

// ファイルを開くダイアログを表示
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

// ファイルを開くダイアログ内で選択したファイル数を数える
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

// ファイルを開くダイアログ内で選択したファイル名へのオフセットを返す
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

// タイトルバーを更新
void updateTitleBar(HWND hwndDlg, HWND hListbox) {
	int max;
	char buf[256];
	
	max = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
	sprintf(buf, VERSION_STR, max);
	SetWindowText(hwndDlg, buf);
}

// メインダイアログの処理
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
		// 初期化
		case WM_INITDIALOG:
			// アイコンを設定
			hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
			SendMessage(hwndDlg, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
			hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
			SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
			
			// プラグイン一覧を読み込み
			hListbox = GetDlgItem(hwndDlg, IDC_LIST_PLUGIN);
			loadPluginList(hListbox);
			
			// コマンドラインから追加
			if(cmdenable) {
				// 新しい項目を追加
				convertFullPathToShort(basedir, cmdline);
				convertYenToSlash(cmdline);
				SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)cmdline);
				
				// カーソルを合わせる
				cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
				SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
			}
			
			updateTitleBar(hwndDlg, hListbox);
			return 1;
		// ボタンクリック
		case WM_COMMAND:
			hListbox = GetDlgItem(hwndDlg, IDC_LIST_PLUGIN);
			
			switch(LOWORD(wParam)) {
				case IDC_BUTTON_ADD:
					// 追加
					if(OpenFileDialog(hwndDlg, filename)) {
						// ファイル数を数える
						temp = countFileNameString(filename);
						
						// 結果が0（＝複数選択していない）場合
						if(temp == 0) {
							// パスを短くする
							convertFullPathToShort(basedir, filename);
							convertYenToSlash(filename);
							
							// 重複チェック
							temp2 = SendMessage(hListbox, LB_FINDSTRING, -1, (LPARAM)filename);
							
							if(temp2 == LB_ERR) {
								// 新しい項目を追加
								SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)filename);
								
								// カーソルを合わせる
								cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
								SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
							} else {
								// 既にある方にカーソルを合わせる
								SendMessage(hListbox, LB_SETCURSEL, temp2, 0);
							}
						}
						// 複数選択している場合
						else {
							for(i = 0; i < temp; i++) {
								// ファイルパスを決める
								strcpy(pluginname, filename);
								strcpy(tempname, filename + getFileNameString(filename, i + 1));
								PathAppend(pluginname, tempname);
								
								// パスを短くする
								convertFullPathToShort(basedir, pluginname);
								convertYenToSlash(pluginname);
								
								// 重複チェック
								temp2 = SendMessage(hListbox, LB_FINDSTRING, -1, (LPARAM)pluginname);
								
								if(temp2 == LB_ERR) {
									// 項目追加
									SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)pluginname);
									
									// カーソルを合わせる
									cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
									SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
								} else {
									// 既にある方にカーソルを合わせる
									SendMessage(hListbox, LB_SETCURSEL, temp2, 0);
								}
							}
						}
						
						// タイトルバー更新
						updateTitleBar(hwndDlg, hListbox);
					}
					return 1;
				case IDC_BUTTON_REMOVE:
					// 削除
					cur = SendMessage(hListbox, LB_GETCURSEL, 0, 0);
					if(cur != LB_ERR) {
						SendMessage(hListbox, LB_DELETESTRING, cur, 0);
						temp = SendMessage(hListbox, LB_SETCURSEL, cur, 0);
						if(temp == LB_ERR) SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
					}
					updateTitleBar(hwndDlg, hListbox);
					return 1;
				case IDC_BUTTON_UP:
					// 上に移動
					movePluginList(hListbox, -1);
					return 1;
				case IDC_BUTTON_DOWN:
					// 下に移動
					movePluginList(hListbox, 1);
					return 1;
				case IDC_BUTTON_OK:
					// OK
					savePluginList(hListbox);
					EndDialog(hwndDlg, 1);
					return 1;
				case IDCANCEL:
					// キャンセル
					EndDialog(hwndDlg, 0);
					return 1;
			}
			break;
		// ドラッグ＆ドロップ
		case WM_DROPFILES:
			hListbox = GetDlgItem(hwndDlg, IDC_LIST_PLUGIN);
			
			// ドロップされたファイル数を取得
			temp = DragQueryFile((HDROP)wParam, 0xFFFFFFFF, NULL, 0);
			
			for(i = 0; i < temp; i++) {
				// ファイル名を取得
				DragQueryFile((HDROP)wParam, i, filename, sizeof(filename));
				
				// ファイル名を短くする
				convertFullPathToShort(basedir, filename);
				convertYenToSlash(filename);
				
				// 重複チェック
				temp2 = SendMessage(hListbox, LB_FINDSTRING, -1, (LPARAM)filename);
				
				if(temp2 == LB_ERR) {
					// 項目追加
					SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)filename);
					
					// カーソルを合わせる
					cur = SendMessage(hListbox, LB_GETCOUNT, 0, 0);
					SendMessage(hListbox, LB_SETCURSEL, cur - 1, 0);
				} else {
					// 既にある方にカーソルを合わせる
					SendMessage(hListbox, LB_SETCURSEL, temp2, 0);
				}
			}
			
			DragFinish((HDROP)wParam);
			
			// タイトルバー更新
			updateTitleBar(hwndDlg, hListbox);
			
			return 1;
		// 終了
		case WM_CLOSE:
			EndDialog(hwndDlg, 0);
			return 1;
	}
	
	return 0;
}

// プログラム開始時に呼ばれるメイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	// カレントディレクトリをheboplugin.exeがある場所にする
	GetModuleFileName(NULL, basedir, BUF_SIZE);
	PathRemoveFileSpec(basedir);
	SetCurrentDirectory(basedir);
	strncpy(filedlgdir, basedir, BUF_SIZE);
	
	// コマンドラインオプション
	cmdenable = 0;
	if(strlen(lpszCmdLine) > 0) {
		strncpy(cmdline, lpszCmdLine, BUF_SIZE);
		cmdenable = 1;
	}
	
	// ダイアログ表示
	hInst = hInstance;
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDialogProc);
	
	return 0;
}
