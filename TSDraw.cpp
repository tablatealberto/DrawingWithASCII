
#include "TSDraw.h"

using namespace std;

InfoGrid TSDraw::grid(int x, int y,  int rows, int columns, int widthColumn, int hightRow, int color){

    InfoGrid ig;

    ig.x = x;
    ig.y = y;
    ig.rows = rows;
    ig.columns = columns;
    ig.widthColumn = widthColumn;
    ig.hightRow = hightRow;
    ig.color = color;

    columns = (columns + 0.5) * (widthColumn +1);
    rows = (rows + 0.5) * (hightRow +1);


	textcolor(color);
	for(int i = 0; i < columns; i+=widthColumn +1){
		gotoxy(x + i ,y);
		lineV(rows,(char)179);
	}
	for(int i = 0; i < rows; i+=hightRow +1){
		gotoxy(x,y + i);
		lineH(columns-1,(char)196);
	}
	for(int i = x; i < x + columns; i+=widthColumn +1){
		for(int j = y; j < y + rows; j+=hightRow +1){
			gotoxy(i,j);
			printf("%c",197);
		}
	}

	return ig;
}

void TSDraw::grid(InfoGrid ig){

    ig.columns = (ig.columns + 0.5) * (ig.widthColumn+1);
    ig.rows = (ig.rows + 0.5) * (ig.hightRow+1);


	textcolor(ig.color);
	for(int i = 0; i < ig.columns; i+=ig.widthColumn+1){
		gotoxy(ig.x + i ,ig.y);
		lineV(ig.rows,(char)179);
	}
	for(int i = 0; i < ig.rows; i+=ig.hightRow+1){
		gotoxy(ig.x,ig.y + i);
		lineH(ig.columns-1,(char)196);
	}
	for(int i = ig.x; i < ig.x + ig.columns; i+=ig.widthColumn+1){
		for(int j = ig.y; j < ig.y + ig.rows; j+=ig.hightRow+1){
			gotoxy(i,j);
			printf("%c",197);
		}
	}
}

void TSDraw::lineV(int large,char sym){
	int x,y;
	x = wherex();
	y = wherey();
	for(int c = 0; c < large; c++){
		gotoxy(x,y++);
		cout<<sym;
	}
}

void TSDraw::lineH(int large,char sym){
	int x,y;
	x = wherex();
	y = wherey();
	for(int c = 0; c < large; c++){
		gotoxy(x++,y);
		cout<<sym;
	}
}

void TSDraw::setSymInCell(int row, int column, InfoGrid ig, int sym){

    gotoxy((column * 2) - 1 + ig.x + (ig.widthColumn - 1) * (column - 1),(row * 2)-1 + ig.y + (ig.hightRow - 1) * (row - 1));
    printf("%c",sym);
 }

void TSDraw::setSymInCell(int row, int column, InfoGrid ig, int sym[], int n_sym){

    int i = 0;
    for(int f = 0; f < ig.widthColumn; f++){
        for(int c = 0; c < ig.hightRow; c++){
            gotoxy(f + (column * 2) - 1 + ig.x + (ig.widthColumn - 1) * (column - 1),
               c + (row * 2)-1 + ig.y + (ig.hightRow - 1) * (row - 1));
               if(i < n_sym) printf("%c", sym[i++]);
               else return;
        }
    }
 }

void TSDraw::setInCellCustom(int row, int column, InfoGrid ig, int sym){

    int x = (column * 2) - 1 + ig.x + (ig.widthColumn - 1) * (column - 1);
    int y = (row * 2)-1 + ig.y + (ig.hightRow - 1) * (row - 1);

    gotoxy(x,y); printf("%i", sym);
    gotoxy(x,y+1); printf(" %c", sym);

}

void TSDraw::drawCuad(int x, int y,  int width, int hight, int color){

    textbackground(BLACK);
    textcolor(color);
    gotoxy(x,y);
    lineH(width,(char)196);
    gotoxy(x,y + hight);
    lineH(width,(char)196);
    gotoxy(x,y);
    lineV(hight,(char)179);
    gotoxy(x + width,y);
    lineV(hight,(char)179);

    gotoxy(x,y);
    printf("%c",218);
    gotoxy(x,y + hight);
    printf("%c",192);
    gotoxy(x + width,y);
    printf("%c",191);
    gotoxy(x + width,y + hight);
    printf("%c",217);
}

void TSDraw::drawSym(int x, int y, int sym){

    gotoxy(x,y);
    printf("%c",sym);
}

void TSDraw::putText(int x, int y, char *text){

    gotoxy(x,y);
    printf(text);
}

void TSDraw::showDrawing(DrawData draw){

    for(int f = 0; f < draw.h; f++){
        for (int c = 0; c < draw.w; c++){
            textcolor(draw.c[c][f]);
            drawSym(c+2, f+3, draw.d[c][f]);
        }
    }
}

