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

void VictoryWindow(int swipe) {
	int letter, i = 0;
	scorelist* leaders = new scorelist[6];
	cleardevice();
	char * sc = new char[255];
	outtextxy(20, getmaxy() / 2 - 160, (char*)"Enter youre");
	outtextxy(180, getmaxy() / 2 - 80, (char*)"name:");
	bar(40, getmaxy() / 2, 90, getmaxy() / 2 + 60);
	outtextxy(40, getmaxy() / 2 + 80, (char*)"Score:");
	_itoa(swipe, sc, 10);
	outtextxy(340, getmaxy() / 2 + 80, sc);
	char b[255] = { 0 };
	while (true) {
		letter = getch();
		if (letter == 27)break;
		else if (letter == 8 && i > 0) {
			b[i] = ' ';
			outtextxy(40, getmaxy() / 2, b);
			i--;
			bar(i * 51 + 40, getmaxy() / 2 + 10, i * 51 + 90, getmaxy() / 2 + 80);
		}
		else if (letter == 13) {
			for (int j = 0; j < 10; j++) {
				if (leaders[i].scor > swipe) {
					leaders[i].scor = swipe;
					leaders[i].n = sc;
					leaders[i].name = b;
					break;
				}
			}
			Globalscore(leaders);
			break;
		}
		else if (i < 9 && letter>32 && letter < 127) {
			b[i] = (char)letter;
			outtextxy(40, getmaxy() / 2, b);
			i++;
			bar(i * 51 + 40, getmaxy() / 2 + 10, i * 51 + 90, getmaxy() / 2 + 80);
		}
	}
}

void SalutingWindow() {
	settextstyle(0, 0, 3);
	outtextxy(20, 40, (char*)"W - Move EMPTY cell UP");
	outtextxy(20, 80, (char*)"A - Move EMPTY cell LEFT");
	outtextxy(20, 120, (char*)"S - Move EMPTY cell DOWN");
	outtextxy(20, 160, (char*)"D - Move EMPTY cell RIGHT");
	outtextxy(20, 200, (char*)"T - Open Leaders-list");
	outtextxy(240, 280, (char*)"PRESS");
	outtextxy(185, 320, (char*)"<ANNY KEY>");
	outtextxy(170, 360, (char*)"TO CONTINUE");
	getch();
	settextstyle(0, 0, 10);
}
