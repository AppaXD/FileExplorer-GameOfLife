#include <chrono>
#include <random>

#include "Grid.h";
#include "Cell.h";

std::mt19937 rng;

int rand(int rangeMin, int rangeMax)
{
	std::uniform_int_distribution<int> uid(rangeMin, rangeMax);
	return uid(rng);
}

int main()
{
	std::string defaultName = "--------------------------------------------------------------------------------------------------------------";


	int w = defaultName.length();
	int h = 32;

	Engine engine("game");
	engine.clear();
	engine.create();

	for (int i = 0; i < 32; i++)
	{
		engine.addLine(i, defaultName);
	}

	std::vector<std::string> edits;
	for (int i = 0; i < 32; i++)
	{
		edits.push_back(defaultName);
	}

	Cell cell(Vector2(0, 0), 0);
	std::vector<std::vector<Cell>> grid;
	for (int i = 0; i < w; i++)
	{
		std::vector<Cell> tempCells;
		for (int j = 0; j < h; j++) 
		{
			cell.position = Vector2(i, j);
			cell.state = 0;
			int isAlive = rand(1, 10) == 5;
			if (isAlive)
			{
				cell.state = 1;
				edits[j][i] = 'x';
			}

			tempCells.push_back(cell);
		}
		grid.push_back(tempCells);
	}

	for (int i = 0; i < edits.size(); i++)
	{
		engine.editLine(i, edits[i]);
	}

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	// main game loop
	while (1)
	{
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		float elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();

		if (elapsed >= 1.05)
		{
			t1 = std::chrono::high_resolution_clock::now();

			for (int x = 0; x < w; x++)
			{
				for (int y = 0; y < h; y++)
				{
					int state = grid[x][y].state;

					if (state == 1)
					{
						int neighbours = 0;

						if (x > 0)
							neighbours += grid[x - 1][y].state;
						if (x < w - 2)
							neighbours += grid[x + 1][y].state;
						if (y > 0)
							neighbours += grid[x][y - 1].state;
						if (y < h - 2)
							neighbours += grid[x][y + 1].state;
						if (x > 0 && y > 0)
							neighbours += grid[x - 1][y - 1].state;
						if (x < w - 2 && y > 0)
							neighbours += grid[x + 1][y - 1].state;
						if (x > 0 && y < h - 2)
							neighbours += grid[x - 1][y + 1].state;
						if (x < w - 2 && y < h - 2)
							neighbours += grid[x + 1][y + 1].state;

						if (neighbours < 2 || neighbours > 3)
						{
							edits[y][x] = '-';
							grid[x][y].state = 0;
						}
					}
					else
					{
						int neighbours = 0;

						if (x > 0)
							neighbours += grid[x - 1][y].state;
						if (x < w - 2)
							neighbours += grid[x + 1][y].state;
						if (y > 0)
							neighbours += grid[x][y - 1].state;
						if (y < h - 2)
							neighbours += grid[x][y + 1].state;
						if (x > 0 && y > 0)
							neighbours += grid[x - 1][y - 1].state;
						if (x < w - 2 && y > 0)
							neighbours += grid[x + 1][y - 1].state;
						if (x > 0 && y < h - 2)
							neighbours += grid[x - 1][y + 1].state;
						if (x < w - 2 && y < h - 2)
							neighbours += grid[x + 1][y + 1].state;

						if (neighbours == 3)
						{
							edits[y][x] = 'x';
							grid[x][y].state = 1;
						}
					}
				}
			}
			for (int i = 0; i < edits.size(); i++)
			{
				engine.editLine(i, edits[i]);
			}
		}
	}
} 