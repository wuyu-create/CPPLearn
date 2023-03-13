#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Snake.h"

#define MAPH 20
#define MAPW 50

#define KONG 0
#define WALL 1
#define SNAKE 3
#define FOOD 2

enum class Direction { UP, DOWN, LEFT, RIGHT };

class SnakeGame
{
public:
	SnakeGame();
	~SnakeGame();

	bool is_GameOver();

	void control();       // 控制

private:
	int map[MAPH][MAPW];  // 地图
	Snake sk;             // 蛇
	Direction direction;  // 初始方向
	bool isGameOver;

	bool is_exit_food;

	void InitSnake();     // 初始化蛇

	void InitMap();       // 初始化地图

	void randomSnack();   // 随机生成食物

	void printMap();      // 打印地图
	
	void autoMove();      // 移动
};




