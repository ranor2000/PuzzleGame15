#pragma once
#include "stdafx.h"

#include "graphicsboard.h"
#include "shift.h"
#include "generation.h"

void ProcessGame(byte** field);

bool VictoryCheck(byte** field, int swipe);

// output board in console
void OutputBoard(byte** field);