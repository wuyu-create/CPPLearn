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

	void control();       // ����

private:
	int map[MAPH][MAPW];  // ��ͼ
	Snake sk;             // ��
	Direction direction;  // ��ʼ����
	bool isGameOver;

	bool is_exit_food;

	void InitSnake();     // ��ʼ����

	void InitMap();       // ��ʼ����ͼ

	void randomSnack();   // �������ʳ��

	void printMap();      // ��ӡ��ͼ
	
	void autoMove();      // �ƶ�
};




