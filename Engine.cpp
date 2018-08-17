#include "Engine.h"

#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem::v1;

void Engine::addLine(int line, std::string contents)
{
	std::string strLine;
	if (line < 10)
	{
		strLine = "0" + std::to_string(line);
	}
	else strLine = std::to_string(line);
	std::string name = dir + "/" + strLine + contents;
	std::ofstream file(name);
	file.close();

	files.push_back(name);
	fileNames.push_back(contents);
}

void Engine::editLine(int line, std::string contents)
{
	if (line >= 0)
	{
		std::string strLine;
		if (line < 10)
		{
			strLine = "0" + std::to_string(line);
		} else strLine = std::to_string(line);
		std::string oldName = files[line];
		std::string newName = dir + "/" + strLine + contents;

		rename(oldName.c_str(), newName.c_str());

		files[line] = newName;
		fileNames[line] = contents;
	}
}

void Engine::clear()
{
	for (auto & f : fs::directory_iterator(dir))
	{
		fs::remove_all(dir);
	}
}

void Engine::create()
{
	fs::create_directory(dir);
}

std::string Engine::getLine(int line)
{
	return files[line];
}

std::string Engine::getFileName(int line)
{
	return fileNames[line];
}

Engine::Engine(std::string directory)
{
	dir = directory;
}

Vector2::Vector2(int nx, int ny)
{
	x = nx;
	y = ny;
}

Entity::Entity(int nx, int ny, int nsx, int nsy)
{
	position = Vector2(nx, ny);
	size = Vector2(nsx, nsy);
}
