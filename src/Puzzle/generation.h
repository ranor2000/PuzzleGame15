#pragma once
#include "stdafx.h"

#define EMPTY byte(0)

/// sum of every field must be:
///   01 + 02 + 03 + 04 +
/// + 05 + 06 + 07 + 08 +
/// + 09 + 10 + 11 + 12 +
/// + 13 + 14 + 15 + (EMPTY) = 120 + (EMPTY) = 243

byte** GenerateNewField(byte countOfShuffle);