
#include "TSGUI.h"

TSGUI::TSGUI(){

    p_draw = new TSDraw;

    createASCIITable(28,7);
    ShowASCIITable(65,1,2);

    SelectInASCIITable(1,1);
    brush.x = 1;
    brush.y = 1;

    createDrawArea();

    loadDraw();

}

void TSGUI::createASCIITable(int rows, int columns){

    ATable.rows = rows;
    ATable.columns = columns;

    int amout = 0;
    int i = 0;
    for(int f = 1; f <= ATable.rows; f++)
    {
        for(int c = 1; c <= ATable.columns; c++)
        {

            if(i == 7) i = 11;
            //if(i == 49) i = 91;
            if(i == 97) i = 123;
            if(i == 129) i = 166; //tildes
            if(i == 255)
            {
                f = ATable.rows;
                c = ATable.columns;
                //cout<<amout;
                break;
            }
            amout++;
            ATable.matriz[f][c] = i++;

        }

    }
}

void TSGUI::ShowASCIITable(int x, int y, int lineSpacing){

    ATable.x = x;
    ATable.y = y;
    ATable.lineSpacing = lineSpacing;

    textcolor(WHITE);
    p_draw->putText(x,y,"      ASCII");
    int i = 0;
    for(int f = 1; f <= ATable.rows; f++)
    {
        for(int c = 1; c <= ATable.columns; c++)
        {
            p_draw->drawSym(x + c  * ATable.lineSpacing,  y + f, ATable.matriz[f][c]);
        }

    }
}

void TSGUI::moveInASCIITable(TypeMove tm){

    bool flag = false;
    int f = selectedSym.f;
    int c = selectedSym.c;

    switch(tm)
    {
    case LEFT:
        if(c > 1)
        {
            flag = true;
            c--;
        }
        break;
    case RIGHT:
        if(c < ATable.columns)
        {
            flag = true;
            c++;
        }
        break;
    case DOWN:
        if(f < ATable.rows)
        {
            flag = true;
            f++;
        }
        break;
    case UP:
        if(f > 1)
        {
            flag = true;
            f--;
        }
        break;
    }

    if(flag)
    {
        textbackground(BLACK);
        textcolor(WHITE);
        p_draw->drawSym(ATable.x + selectedSym.c * ATable.lineSpacing, ATable.y + selectedSym.f, ATable.matriz[selectedSym.f][selectedSym.c]);
        SelectInASCIITable(f,c);
    }
}

void TSGUI::SelectInASCIITable(int f, int c){

    textbackground(GREEN);
    p_draw->drawSym(ATable.x + c  * ATable.lineSpacing, ATable.y + f, ATable.matriz[f][c]);
    selectedSym.f = f;
    selectedSym.c = c;

}

void TSGUI::createDrawArea(int w , int h){

     p_draw->drawCuad(1,2,w,h,RED);
}

void TSGUI::moveInArea(TypeMove tm){

    bool flag = false;
    int x = brush.x;
    int y = brush.y;

    switch(tm)
    {
        case LEFT:
            if(x > 1)
            {
                flag = true;
                x--;
            }
            break;
        case RIGHT:
            if(x < 64)
            {
                flag = true;
                x++;
            }
            break;
        case DOWN:
            if(y < 28)
            {
                flag = true;
                y++;
            }
            break;
        case UP:
            if(y > 1)
            {
                flag = true;
                y--;
            }
            break;
    }



    if(flag)
    {
        textbackground(BLACK);
        textcolor(drawData.c[brush.x-1][brush.y-1]);
        p_draw->drawSym(1 + brush.x, 2 + brush.y, drawData.d[brush.x-1][brush.y-1]);
        brush.x = x;
        brush.y = y;
        showBrush();
    }
}

void TSGUI::showBrush(){

    textbackground(DARKGRAY);
    textcolor(drawData.c[brush.x-1][brush.y-1]);
    p_draw->drawSym(1 + brush.x, 2 + brush.y, drawData.d[brush.x-1][brush.y-1]);
}

void TSGUI::PutSymInArea(){

    textbackground(DARKGRAY);
    textcolor(drawData.c[brush.x-1][brush.y-1]);
    p_draw->drawSym(1 + brush.x, 2 + brush.y, ATable.matriz[selectedSym.f][selectedSym.c]);
    drawData.d[brush.x-1][brush.y-1] = ATable.matriz[selectedSym.f][selectedSym.c];

}

void TSGUI::setColorInSym(int color){

    if(drawData.d[brush.x-1][brush.y-1] != 0){
        drawData.c[brush.x-1][brush.y-1] = 7+color;
        textcolor(drawData.c[brush.x-1][brush.y-1]);
        p_draw->drawSym(1 + brush.x,2 + brush.y,drawData.d[brush.x-1][brush.y-1]);
    }
}

void TSGUI::loadDraw(){

    fstream myfile;
    myfile.open ("draw.bin",  ios::in | ios::binary);
    myfile.seekg (0);
    myfile.read((char*)&drawData.w,sizeof drawData.w);
    myfile.read((char*)&drawData.h,sizeof drawData.h);
    myfile.read((char*)&drawData, sizeof drawData);
    myfile.close();

    p_draw->showDrawing(drawData);

//    for(int f = 0; f < drawData.h; f++){
//        for (int c = 0; c < drawData.w; c++){
//            drawData.d[c][f] = 0;
//            drawData.c[c][f] = 7+8;
//        }
//    }

}


void TSGUI::saveDraw(){

    fstream myfile;
    myfile.open ("draw.bin", ios::out | ios::binary);
    myfile.seekp (0);

    myfile.write(reinterpret_cast<const char*>(&drawData.w),sizeof drawData.w);
    myfile.write(reinterpret_cast<const char*>(&drawData.h),sizeof drawData.h);
    myfile.write(reinterpret_cast<const char*>(&drawData),sizeof drawData);
    myfile.close();

}



