#pragma once

#include <vector>

class Engine
{
private:
	std::vector<std::string> files;
	std::vector<std::string> fileNames;
	std::string dir;
public:
	Engine::Engine(std::string directory);
	void Engine::addLine(int line, std::string contents);
	void Engine::editLine(int line, std::string contents);
	void Engine::clear();
	void Engine::create();
	std::string Engine::getLine(int line);
	std::string Engine::getFileName(int line);
};

class Vector2
{
public:
	Vector2::Vector2(int nx, int ny);
	Vector2()
	{
		x = 0;
		y = 0;
	}
	int x, y;
};

class Entity
{
public:
	Vector2 position;
	Vector2 size;
	Entity::Entity(int nx, int ny, int nsx, int nsy);
};