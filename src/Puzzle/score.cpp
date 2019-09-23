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

