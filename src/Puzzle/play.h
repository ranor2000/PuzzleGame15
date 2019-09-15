#pragma once

#include "stdafx.h"
#include "shift.h"
#include "generation.h"

void NewBoard(byte** field);

void ProcessGame(byte** field);

int VictoryCheck(byte** field);