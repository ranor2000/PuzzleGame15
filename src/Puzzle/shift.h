#pragma once
#include "stdafx.h"

#define EMPTY byte(0)

enum MoveDirection {
	DownToUp,		// W (87, 119, 150, 230)
	LeftToRight,	// A (68, 100, 130, 162)
	UpToDown,		// S (83, 115, 155, 235)
	RightToLeft		// D (65, 97, 148, 228)
};

void swap(byte& a, byte& b);

MoveDirection KeyCheckConslole();

MoveDirection KeyCheck(char key);

void RectangelMove(MoveDirection direction, byte** field);