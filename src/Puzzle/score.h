#pragma once
#include "stdafx.h"
#include "play.h"

#define WORK_FILE "player.bin"

#define WORDSIZE 10

struct scorelist {
	int scor = 300;
	char n[WORDSIZE] = { 0 };
	char name[WORDSIZE] = { 0 };
};

void loadscore(scorelist* leaders);

void savescore(scorelist* leaders);