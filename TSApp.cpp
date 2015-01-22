#include "TSDraw.h"
#include "TSGUI.h"
#include "TSApp.h"

int const KEY_UP = 72;
int const KEY_DOWN = 80;
int const KEY_LEFT = 75;
int const KEY_RIGHT = 77;

int const KEY_SPACE = 32;
int const KEY_ENTER = 13;
int const KEY_ESC = 27;
int const KEY_F2 = 60;


int const KEY_W = 119;
int const KEY_A = 97;
int const KEY_S = 115;
int const KEY_D = 100;


int const KEY_1 = 49;
int const KEY_2 = 50;
int const KEY_3 = 51;
int const KEY_4 = 52;
int const KEY_5 = 53;
int const KEY_6 = 54;
int const KEY_7 = 55;
int const KEY_8 = 56;


void TSApp::init(){

    p_gui = new TSGUI;

}

void TSApp::controlKeyEvents(){

    bool _continue = true;
    int key = 0;

	while(_continue){
		if(kbhit()){
			key = getch();
			switch(key){
				case KEY_UP: {
					p_gui->moveInASCIITable(UP);
					break;
				}
				case KEY_DOWN: {
                    p_gui->moveInASCIITable(DOWN);
					break;
				}
				case KEY_LEFT: {
                     p_gui->moveInASCIITable(LEFT);
					break;
				}
				case KEY_RIGHT: {
                    p_gui->moveInASCIITable(RIGHT);
					break;
				}
				case KEY_W: {
                    p_gui->moveInArea(UP);
					break;
				}
				case KEY_A:  {
                    p_gui->moveInArea(LEFT);
					break;
				}
				case KEY_S: {
                    p_gui->moveInArea(DOWN);
					break;
				}
				case KEY_D: {
                    p_gui->moveInArea(RIGHT);
					break;
				}
				case KEY_SPACE: {
                    p_gui->PutSymInArea();
					break;
				}
				case KEY_1: {
                    p_gui->setColorInSym(1);
					break;
				}
				case KEY_2: {
                    p_gui->setColorInSym(2);
					break;
				}
				case KEY_3: {
                    p_gui->setColorInSym(3);
					break;
				}
				case KEY_4: {
                    p_gui->setColorInSym(4);
					break;
				}
				case KEY_5: {
                    p_gui->setColorInSym(5);
					break;
				}
				case KEY_6: {
                    p_gui->setColorInSym(6);
					break;
				}
				case KEY_7: {
                    p_gui->setColorInSym(7);
					break;
				}
				case KEY_8: {
                    p_gui->setColorInSym(8);
					break;
				}
				case KEY_F2: {
                    p_gui->saveDraw();
					break;
				}

			}
			key = 0;
		}
	}
}
