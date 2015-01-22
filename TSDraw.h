#ifndef TSDRAW_H
#define TSDRAW_H

#include <conio2.h>
#include <stdio.h>
#include <iostream>


typedef struct{
    int w = 64;
    int h = 28;
    int d[64][28];
    int c[64][28];
}DrawData;

typedef struct{
    int x;
    int y;
}Brush;

typedef struct{
    int x;
    int y;
    int rows;
    int columns;
    int widthColumn;
    int hightRow;
    int color;
} InfoGrid;


class TSDraw{

    public:
        InfoGrid grid(int x, int y,  int rows, int columns, int widthColumn = 1, int hightRow = 1, int color = 3);
        void grid(InfoGrid ig);
        void lineH(int large,char sym);
        void lineV(int large,char sym);
        void setSymInCell(int row, int column, InfoGrid ig, int sym);
        void setSymInCell(int row, int column, InfoGrid ig, int sym[], int n_sym);
        void setInCellCustom(int row, int column, InfoGrid ig, int sym);
        void drawCuad(int x, int y,  int width, int hight, int color);
        void drawSym(int x, int y, int sym);
        void putText(int x, int y, char *text);
        void showDrawing(DrawData draw);

};

#endif // TSDRAW_H
