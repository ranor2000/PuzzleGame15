#include "graphicsboard.h"

void InitializationGraphics() {
	int GrDr, GrMod, rez;
	GrDr = DETECT;
//	initgraph(&GrDr, &GrMod, (char*)" ");
	initwindow(800, 600);
	rez = graphresult();
	if (rez != grOk) {
		printf("Initialization failed: %s\n", grapherrormsg(rez));
		printf("Press any key");
		getch();
		exit(1);
	}
}

void BoardOutput(byte** field) {
	int xx, yy;
	char * fieldonchar = new char[255];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			bar(j * (getmaxx() / 4) + 10, i * (getmaxy() / 4) + 10, (j + 1) * (getmaxx() / 4) - 10, (i + 1) * (getmaxy() / 4) - 10);
			if (field[i][j] == EMPTY)continue;
			if (field[i][j] < 10)
				xx = 50 + (j) * (getmaxx() / 4);
			else
				xx = 24 + (j) * (getmaxx() / 4);
			yy = 20 + (i) * (getmaxy() / 4);
			_itoa(field[i][j], fieldonchar, 10);
			outtextxy(xx, yy, fieldonchar);
		}
}			

void VictoryWindow() {
	cleardevice();
	outtextxy(110, getmaxy() / 2 - 90, (char*)"Victory");
}

void SalutingWindow() {
	outtextxy(20, 40, (char*)"W - Move EMPTY cell UP");
	outtextxy(20, 80, (char*)"A - Move EMPTY cell LEFT");
	outtextxy(20, 120, (char*)"S - Move EMPTY cell DOWN");
	outtextxy(20, 160, (char*)"D - Move EMPTY cell RIGHT");
	outtextxy(20, 200, (char*)"T - Open Leaders-list");
	outtextxy(240, 280, (char*)"PRESS");
	outtextxy(185, 320, (char*)"<ANNY KEY>");
	outtextxy(170, 360, (char*)"TO CONTINUE");
}
