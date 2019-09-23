#pragma once
#include "stdafx.h"

#include "play.h"
#include "score.h"

void BoardOutput(byte** field);

void VictoryWindow(int swipe);

void SalutingWindow();

void Globalscore(scorelist* leaders);