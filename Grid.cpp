#include "Grid.h"

Grid::Grid(std::vector<std::vector<Cell>> mCells)
{
	cells = mCells;
}

int Grid::getState(Vector2 pos)
{
	return cells[pos.x][pos.y].state;
}

Cell Grid::getCell(Vector2 pos)
{
	return cells[pos.x][pos.y];
}
