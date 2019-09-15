#include "score.h"

void savescore(struct scorelist *leaders) {
	FILE* fn;
	fn = fopen("player.bin", "wb");
	fwrite(&leaders, sizeof(leaders), 10, fn);
	fclose(fn);
}





void loadscore(struct scorelist* leaders) {
	FILE* fn;
	fn = fopen("player.bin", "rb");
	fread(&leaders, sizeof(leaders), 10, fn);
	fclose(fn);
}