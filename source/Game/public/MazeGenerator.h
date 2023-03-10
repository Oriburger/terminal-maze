#pragma once
#include "../../Core/public/Core.h"

/*
- Date : 23/03/02 LJH
- Class
	- MazeGenerator
		- RecursiveRandomMazeGenerator
		- NonRecursiveRandomMazeGenerator
- Description
	- std 기능을 포함한 가장 기본 라이브러리를 포함하는 헤더
	- 팩토리 패턴을 활용하여 Maze를 Client에게 반환
	- RecursiveRandomMazeGenerator
		- 재귀적인 알고리즘으로 (DFS Base) 미로를 생성
	- NonRecursiveRandomMazeGenerator
		- 비재귀적인 알고리즘으로 (BFS Base) 미로를 생성
*/

class MazeGenerator
{
public:
	MazeGenerator() = default;

	~MazeGenerator() = default; 

	virtual class Maze* GenerateNewMaze(int Length) = 0;

	virtual class Maze* GenerateNewMaze(int Width, int Height) = 0;
};

class RecursiveRandomMazeGenerator : public MazeGenerator
{
public:
	RecursiveRandomMazeGenerator()	{ randGenerator = new RandomIntegerValueGenerator(0, 40000); }

	~RecursiveRandomMazeGenerator()  { delete randGenerator; }

public:
	virtual class Maze* GenerateNewMaze(int Length) override;

	virtual class Maze* GenerateNewMaze(int Height, int Width) override;

private:
	class RandomIntegerValueGenerator* randGenerator; 

	Location2D RecursiveMazeSearch(class Maze* MyMaze, Location2D CurrLocation, Location2D PrevLocation = {0, 0});
};