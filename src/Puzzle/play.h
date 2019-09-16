#pragma once
#include "stdafx.h"

#include "graphicsboard.h"
#include "shift.h"
#include "generation.h"

struct scorelist {
	int scor = 0;
	char* n = new char[10];
	char* name = new char[10];
};

void ProcessGame(byte** field);

bool VictoryCheck(byte** field, int swipe);

// output board in console
void OutputBoard(byte** field);