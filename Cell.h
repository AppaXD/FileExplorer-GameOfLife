#pragma once

#include "Engine.h"

class Cell {
public:
	Vector2 position;
	int state;
	Cell::Cell(Vector2 mPosition, int mState);
	Cell()
	{
		position = Vector2(0, 0);
		state = 0;
	}
};