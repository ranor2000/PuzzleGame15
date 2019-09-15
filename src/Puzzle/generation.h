#pragma once
#include "stdafx.h"

#include "shift.h"

#define EMPTY byte(0)

// allocate and return shufled field;
byte** GenerateNewField(int countOfShuffle);

// free memory
void DeleteField(byte** field);