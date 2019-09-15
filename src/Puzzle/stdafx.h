#pragma once
#pragma warning(disable:4273)
#define _CRT_SECURE_NO_WARNINGS
// This header used only for precopmiled libraries

#include <Windows.h>

#include <stdio.h>

#include <time.h>


#include "GraphicsLib/graphics.h"

struct scorelist { int scor = 0; char* n = new char[10]; char* name = new char[10]; };