
#define _WIN32_WINNT 0x0500
#include <windows.h>
#define MWS mainWindowSize

#ifndef TSWINDOW_H
#define TSWINDOW_H

using namespace std;

class TSWindow{

public:
    void resizeWindow(int x, int y,int w,int h);

};

#endif // TSWINDOW_H
