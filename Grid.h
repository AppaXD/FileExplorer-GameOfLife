#pragma once

#include "Cell.h"

class Grid
{
public:
	std::vector<std::vector<Cell>> cells;
	Grid::Grid(std::vector<std::vector<Cell>> mCells);
	int getState(Vector2 pos);
	Cell getCell(Vector2 pos);
};