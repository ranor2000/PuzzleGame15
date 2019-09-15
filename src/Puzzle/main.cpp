#include "stdafx.h"
#include "graphicsboard.h"
#include "play.h"

int main() {
	
	byte** field = nullptr;

	InitializationGraphics;

	ProcessGame(field);

	system("PAUSE");

	return 0;
}