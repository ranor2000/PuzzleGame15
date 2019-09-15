#pragma once
#include "stdafx.h"
#include "play.h"
#define EMPTY byte(0)

enum MoveDirection {
	DownToUp = 0,		// W (87, 119, 150, 230)
	LeftToRight = 1,	// A (68, 100, 130, 162)
	UpToDown = 2,		// S (83, 115, 155, 235)
	RightToLeft = 3,	// D (65, 97, 148, 228)
	None = 4			// no moving
};

void swap(byte& a, byte& b);

MoveDirection KeyCheckConslole();

MoveDirection KeyCheck(char key);

void RectangelMove(MoveDirection direction, byte** field);