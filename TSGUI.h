#ifndef TSGUI_H
#define TSGUI_H

#include <conio2.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "TSDraw.h"

using namespace std;

enum TypeMove{
    LEFT,RIGHT,DOWN,UP
};

typedef struct {
    int x;
    int y;
    int rows;
    int columns;
    int lineSpacing;
    int matriz[28][7];
} ASCIITable;

typedef struct {
    int f;
    int c;
    int sym;
} ASCIISymSelect;

class TSGUI{

public:
    TSDraw *p_draw;
    DrawData drawData;
    Brush brush;
    ASCIITable ATable;
    ASCIISymSelect selectedSym;

public:
    TSGUI();
    void loadDraw();
    void saveDraw();
    void createASCIITable(int rows, int columns);
    void ShowASCIITable(int x, int y, int lineSpacing);
    void moveInASCIITable(TypeMove tm);
    void SelectInASCIITable(int f, int c);
    void createDrawArea(int w = 65, int h = 29);
    void moveInArea(TypeMove tm);
    void showBrush();
    void PutSymInArea();
    void setColorInSym(int color);

};




#endif // TSGUI_H
