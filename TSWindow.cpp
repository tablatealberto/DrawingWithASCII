#include "TSwindow.h"

void TSWindow::resizeWindow(int x, int y, int w,int h){

	HWND mainWindow = GetConsoleWindow();
	SMALL_RECT MWBS = {0,0,0,0};
	MoveWindow(mainWindow, x, y, w, h, TRUE);
	SetConsoleWindowInfo(mainWindow, TRUE, &MWBS);
}


