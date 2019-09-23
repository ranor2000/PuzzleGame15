#include "score.h"

void savescore(scorelist* leaders) {
	FILE* fn = fopen(WORK_FILE, "wb");
	fwrite(leaders, sizeof(scorelist), 6, fn);
	fclose(fn);
}

void loadscore(scorelist* leaders) {
	FILE* fn = fopen(WORK_FILE, "rb");
	if (fn == NULL)
		return;

	fread(leaders, sizeof(scorelist), 6, fn);
	fclose(fn);
}

void Globalscore(scorelist* leaders) {
	int n = 0;
	cleardevice();

	for (int i = 0; i < 6; i++) {
		outtextxy(0, n, (leaders + i)->name);
		outtextxy(445, n, (leaders + i)->n);
		n += 80;
	}

	getch();
}

