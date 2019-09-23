#include "graphicsboard.h"

void GlobalScore(scorelist* leaders) {
	int n = 0;
	cleardevice();

	for (int i = 0; i < 6; i++) {
		outtextxy(0, n, (leaders + i)->playerName);
		outtextxy(445, n, (leaders + i)->textScore);
		n += 80;
	}

	getch();
	return;
}

void BoardOutput(byte** field) {
	cleardevice();
	int x, y;
	char* fieldonchar = new char[255];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == EMPTY)
				continue;

			bar(j * (getmaxx() / 4) + 10, i * (getmaxy() / 4) + 10, (j + 1) * (getmaxx() / 4) - 10, (i + 1) * (getmaxy() / 4) - 10);

			if (field[i][j] < 10)
				x = 50 + (j) * (getmaxx() / 4);
			else
				x = 24 + (j) * (getmaxx() / 4);

			y = 20 + (i) * (getmaxy() / 4);
			_itoa(field[i][j], fieldonchar, 10);
			outtextxy(x, y, fieldonchar);
		}
}

void VictoryWindow(int swipe) {
	int letter, i = 0;
	scorelist* leaders = new scorelist[6];
	char* score = new char[255];
	char playerName[255] = { 0 };

	loadscore(leaders);
	cleardevice();

	outtextxy(20, getmaxy() / 2 - 160, (char*)"Enter youre");
	outtextxy(180, getmaxy() / 2 - 80, (char*)"name:");

	bar(40, getmaxy() / 2, 90, getmaxy() / 2 + 60);
	outtextxy(40, getmaxy() / 2 + 80, (char*)"Score:");
	_itoa(swipe, score, 10);
	outtextxy(340, getmaxy() / 2 + 80, score);

	while (true) {
		letter = getch();
		if (letter == 27)break;
		else if (letter == 8 && i > 0) {
			playerName[i] = ' ';
			outtextxy(40, getmaxy() / 2, playerName);
			i--;
			bar(i * 51 + 40, getmaxy() / 2 + 10, i * 51 + 90, getmaxy() / 2 + 80);
		}

		else if (letter == 13) {
			for (int j = 0; j < 6; j++) {
				if (leaders[j].score > swipe) {
					for (int k = 5; k > j; k--) {
						leaders[k].score = leaders[k - 1].score;
						strcpy(leaders[k].textScore, leaders[k - 1].textScore);
						strcpy(leaders[k].playerName, leaders[k - 1].playerName);
					}
					leaders[j].score = swipe;
					strcpy(leaders[j].textScore, score);
					strcpy(leaders[j].playerName, playerName);
					break;
				}
			}
			savescore(leaders);
			GlobalScore(leaders);
			break;
		}

		else if (i < 9 && letter>32 && letter < 127) {
			playerName[i] = (char)letter;
			outtextxy(40, getmaxy() / 2, playerName);
			i++;
			bar(i * 51 + 40, getmaxy() / 2 + 10, i * 51 + 90, getmaxy() / 2 + 80);
		}
	}
}

void SalutingWindow() {
	settextstyle(0, 0, 3);
	cleardevice();

	outtextxy(20, 40, (char*)"W - Move EMPTY cell UP");
	outtextxy(20, 80, (char*)"A - Move EMPTY cell LEFT");
	outtextxy(20, 120, (char*)"S - Move EMPTY cell DOWN");
	outtextxy(20, 160, (char*)"D - Move EMPTY cell RIGHT");
	outtextxy(240, 280, (char*)"PRESS");
	outtextxy(185, 320, (char*)"<ANNY KEY>");
	outtextxy(170, 360, (char*)"TO CONTINUE");

	settextstyle(0, 0, 10);
}