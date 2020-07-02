#ifndef _HEBOPLUGIN_H
#define _HEBOPLUGIN_H

// 定数
#define PLUGIN_LIST_FILE_NAME "plugins.def"
#define OPENDIALOG_FILTER "ygs2k Script (*.c)\0*.c\0All Files (*.*)\0*.*\0\0"
#define VERSION_STR "heboplugin version0.06 - %d plugins"

#define BUF_SIZE 512
#define FILENAME_BUF_SIZE 10000

// プロトタイプ宣言
int loadPluginList(HWND hListbox);
void savePluginList(HWND hListbox);
void movePluginList(HWND hListbox, int mode);
int loadPluginFile(char *filename, char *prefix);
void convertYenToSlash(char *filename);
void convertFullPathToShort(char *basename, char *filename);
BOOL OpenFileDialog(HWND hwnd, char *filename);
int countFileNameString(char *filename);
int getFileNameString(char *filename, int number);
void updateTitleBar(HWND hwndDlg, HWND hListbox);
BOOL CALLBACK MainDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow);

#endif /* _HEBOPLUGIN_H */
