
#include "TSWindow.h"
#include "TSApp.h"

#include "TSDraw.h"

void text(){
	gotoxy(1,1);
	printf("F2: Save. WASD: Move to drawing. Key direction: Move to table. ");

    gotoxy(1,32);
	printf("Colors: ");
    for(int i = 1; i <= 8; i++){
        gotoxy(wherex(),wherey());
        textcolor(7+i);
        cout<<i<<" ";
    }
	gotoxy(40,32);
	printf("By Tablate Aquino, Alberto");
}

int main(int argc, char *agrv[]){

    TSWindow *win = new TSWindow;
    win->resizeWindow(1,1,1500,700);

    text();

    TSApp *app = new TSApp;
    app->init();
    app->controlKeyEvents();


//    bool _continue = true;
//    int key = 0;
//
//	while(_continue){
//		if(kbhit()){
//			key = getch();
//			cout<<key<<endl;
//			key = 0;
//		}
//	}


    getch();

    return 0;

}


