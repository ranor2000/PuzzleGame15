#pragma once
#include "stdafx.h"

#define WORK_FILE "player.bin"

#define WORDSIZE 10
#define SCORE_LIST_SIZE 6

struct scorelist {
	int score = 300;
	char textScore[WORDSIZE] = { 0 };
	char playerName[WORDSIZE] = { 0 };
};

void loadscore(scorelist* leaders);

void savescore(scorelist* leaders);