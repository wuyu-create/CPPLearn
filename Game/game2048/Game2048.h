#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <conio.h>

enum class Direction { UP, DOWN, LEFT, RIGHT };
class Game2048
{

public:
	Game2048(int bsize = 4, int rnumber = 2, int goal = 2048);

	void initBoard();

	void printBoard();

	static void clearScreen();

	void move(Direction direction);

	void contral();

	bool isGameOver();

	void placeRandomNumber();

private:

	vector<vector<int>> board;
	const int BOARD_SIZE;
	const int MAX_RANDOM_NUMBER;
	const int GOAL_NUMBER;
};