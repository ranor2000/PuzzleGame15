#pragma once

#include "stdafx.h"
#include "shift.h"
#include "generation.h"

void NewBoard(byte** field);

void ProcessGame(byte** field);

bool VictoryCheck(byte** field);

// output board in console
void OutputBoard(byte** field);