#include "SnakeGame.h"

SnakeGame::SnakeGame()
{
	srand(time(NULL));
	direction = Direction::LEFT;
	isGameOver = false;
	memset(map, 0, sizeof(map));

	InitMap();

	InitSnake();

	randomSnack();
}

SnakeGame::~SnakeGame()
{
}

bool SnakeGame::is_GameOver()
{
	return isGameOver;
}
void SnakeGame::control()
{

	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 'w':
			if (direction == Direction::DOWN)
			{
				isGameOver = true;
			}
			direction = Direction::UP;
			break;
		case 's':
			if (direction == Direction::UP)
			{
				isGameOver = true;
			}
			direction = Direction::DOWN;
			break;
		case 'a':
			if (direction == Direction::RIGHT)
			{
				isGameOver = true;
			}
			direction = Direction::LEFT;
			break;
		case 'd':
			if (direction == Direction::LEFT)
			{
				isGameOver = true;
			}
			direction = Direction::RIGHT;
			break;
		default:
			break;
		}
	}
	autoMove();

	if (isGameOver)
		return;

	if (!is_exit_food)
	{
		randomSnack();
		is_exit_food = true;
	}
	system("cls");
	printMap();
}

void SnakeGame::InitSnake()
{
	int c_x = MAPH / 2;
	int c_y = MAPW / 2;
	sk.push_back(c_x, c_y);
	sk.push_back(c_x, c_y + 1);
	map[c_x][c_y] = SNAKE;
	map[c_x][c_y + 1] = SNAKE;
}

void SnakeGame::InitMap()
{
	for (int i = 0; i < MAPH; i++)
	{
		map[i][0] = WALL;
		map[i][MAPW - 1] = WALL;
	}

	for (int i = 0; i < MAPW; i++)
	{
		map[0][i] = WALL;
		map[MAPH - 1][i] = WALL;
	}

}

void SnakeGame::randomSnack()
{
	vector<pair<int, int>> empty;
	for (int i = 1; i < MAPH - 1; i++)
	{
		for (int j = 1; j < MAPW - 1; j++)
		{
			if (map[i][j] == 0)
			{
				empty.push_back(make_pair(i, j));
			}
		}
	}
	int randomIdx = rand() % empty.size();
	map[empty[randomIdx].first][empty[randomIdx].second] = FOOD;
	is_exit_food = true;
}

void SnakeGame::printMap()
{
	for (int i = 0; i < MAPH; i++)
	{
		for (int j = 0; j < MAPW; j++)
		{
			if (map[i][j] == WALL)
			{
				cout << "+";
			}
			else if (map[i][j] == KONG) // 可移动
			{
				cout << " ";
			}
			else if (map[i][j] == FOOD) // 食物
			{
				cout << "w";
			}
			else if (map[i][j] == SNAKE) // snake
			{
				cout << "s";
			}
		}
		cout << endl;
	}
}

void SnakeGame::autoMove()
{
	int newHx, newHy;
	pair<int, int> snakeHead = sk.get_Head();
	newHx = snakeHead.first;
	newHy = snakeHead.second;
	if (direction == Direction::UP)
	{
		newHx = snakeHead.first - 1;
	}
	else if (direction == Direction::DOWN)
	{
		newHx = snakeHead.first + 1;
	}
	else if (direction == Direction::LEFT)
	{
		newHy = snakeHead.second - 1;
	}
	else if (direction == Direction::RIGHT)
	{
		newHy = snakeHead.second + 1;
	}

	// 判断是否碰墙
	if (map[newHx][newHy] == WALL)
	{
		isGameOver = true;
		return;
	}

	// 是否撞
	if (sk.isSelfCrash(newHx, newHy))
	{
		isGameOver = true;
		return;
	}

	// 是否有食物
	if (map[newHx][newHy] == FOOD)
	{
		sk.push_front(newHx, newHy);
		map[newHx][newHy] = SNAKE;
		is_exit_food = false;
	}
	else
	{
		sk.push_front(newHx, newHy);
		map[newHx][newHy] = SNAKE;
		pair<int, int> skTail = sk.get_tail();
		map[skTail.first][skTail.second] = KONG;
		sk.pop_back();
	}

}