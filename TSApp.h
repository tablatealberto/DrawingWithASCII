#ifndef TSAPP_H
#define TSAPP_H

#include <conio2.h>
#include <stdio.h>
#include <iostream>

#include "TSGUI.h"

class TSApp{

public:
    TSGUI *p_gui;

public:
    void init();
    void controlKeyEvents();
    void loadDraw();
    void saveDraw();
};



#endif // TSAPP_H
