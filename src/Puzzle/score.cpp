#include "score.h"

void savescore(scorelist* leaders) {
	FILE* fn;
	fn = fopen("player.bin", "wb");
	fwrite(&leaders, sizeof(leaders), 6, fn);
	fclose(fn);
}

void loadscore(scorelist* leaders) {
	FILE* fn;
	fn = fopen("player.bin", "rb");
	fread(&leaders, sizeof(leaders), 6, fn);
	fclose(fn);
}

void Globalscore(scorelist* leaders) {
	int n = 0;
	cleardevice();
	for (int i = 0; i < 10; i++) {
		outtextxy(20, n, leaders[i].name);
		outtextxy(480, n, leaders[i].n);
		n += 80;
	}
	savescore(leaders);
}

