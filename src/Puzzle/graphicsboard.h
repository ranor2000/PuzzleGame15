#pragma once
#include "stdafx.h"

#include "score.h"
#include "play.h"

void GlobalScore(scorelist* leaders);

void BoardOutput(byte** field);

void VictoryWindow(int swipe);

void SalutingWindow();