#include "Game2048.h"
Game2048::Game2048(int bsize, int rnumber, int goal) : BOARD_SIZE(bsize), MAX_RANDOM_NUMBER(rnumber), GOAL_NUMBER(goal)
{
	srand(time(NULL));
	initBoard();

}


void Game2048::initBoard()
{
	board = vector<vector<int>>(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

	for (int i = 0; i < MAX_RANDOM_NUMBER; i++)
	{
		int row = rand() % BOARD_SIZE;

		int col = rand() % BOARD_SIZE;

		board[row][col] = (rand() % 2 + 1) * 2;
	}
}

void Game2048::printBoard()
{
	clearScreen();
	cout << "2048\n\n";
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void Game2048::clearScreen()
{
	std::cout << "\033[2J"; // 清屏，将终端中所有内容清除
	std::cout << "\033[1;1H"; // 将光标移动到第一行第一列
	//system("cls");
}

void Game2048::move(Direction direction)
{
	bool move = false;
	switch (direction)
	{

	case Direction::UP:
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			int currRow = 0;
			for (int i = 1; i < BOARD_SIZE; i++)
			{
				if (board[i][j] != 0)
				{
					if (board[currRow][j] == 0)
					{
						board[currRow][j] = board[i][j];
						board[i][j] = 0;
						move = true;
					}
					else if (board[currRow][j] == board[i][j])
					{
						board[currRow][j] *= 2;
						board[i][j] = 0;
						move = true;
					}
					currRow++;
				}
			}
		}
		break;
	case Direction::DOWN:
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			int currRow = BOARD_SIZE - 1;
			for (int i = BOARD_SIZE - 2; i >= 0; i--)
			{
				if (board[i][j] != 0)
				{
					if (board[currRow][j] == 0)
					{
						move = true;
						board[currRow][j] = board[i][j];
						board[i][j] = 0;
					}
					else if (board[currRow][j] == board[i][j])
					{
						move = true;
						board[currRow][j] *= 2;
						board[i][j] = 0;
					}
					currRow--;
				}
			}
		}
		break;
	case Direction::LEFT:
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			int currCol = 0;
			for (int j = 1; j < BOARD_SIZE; j++)
			{
				if (board[i][j] != 0)
				{
					if (board[i][currCol] == 0)
					{
						board[i][currCol] = board[i][j];
						board[i][j] = 0;
						move = true;
					}
					else if (board[i][currCol] == board[i][j])
					{
						board[i][currCol] *= 2;
						board[i][j] = 0;
						move = true;
					}
					currCol++;
				}
			}
		}
		break;
	case Direction::RIGHT:
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			//cout << "there" << endl;
			int currCol = BOARD_SIZE - 1;
			for (int j = BOARD_SIZE - 2; j >= 0; j--)
			{
				if (board[i][j] != 0)
				{
					if (board[i][currCol] == 0)
					{
						board[i][currCol] = board[i][j];
						board[i][j] = 0;
						move = true;
					}
					else if (board[i][currCol] == board[i][j])
					{
						board[i][currCol] *= 2;
						board[i][j] = 0;
						move = true;
					}
					currCol--;
				}
			}
		}
		break;
	}

	if (move)
	{
		placeRandomNumber();
	}
}


void Game2048::placeRandomNumber()
{
	vector<pair<int, int>> emptycell;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
			{
				emptycell.push_back(make_pair(i, j));
			}
		}
	}

	if (emptycell.size() > 0)
	{
		int randomIndex = rand() % emptycell.size();
		int randNumber = (rand() % 2 + 1) * 2;
		board[emptycell[randomIndex].first][emptycell[randomIndex].second] = randNumber;
	}
}
// 遍历判断是否结束游戏
// 没有结束条件：
//		1. 存在空格
//      2. 存在两个相邻的位置数值相等
bool Game2048::isGameOver()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (board[i][j] == 0)
			{
				return false;
			}
			if (j < BOARD_SIZE - 1 && board[i][j] == board[i][j + 1])
			{
				return false;
			}

			if (i < BOARD_SIZE - 1 && board[i][j] == board[i + 1][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Game2048::contral()
{
	printBoard();
	while (!isGameOver())
	{
		char ch = _getch();
		Direction direction;
		switch (ch)
		{
		case 'w':
			direction = Direction::UP;
			break;
		case 's':
			direction = Direction::DOWN;
			break;
		case 'a':
			direction = Direction::LEFT;
			break;
		case 'd':
			direction = Direction::RIGHT;
			break;
		default:
			direction = Direction::UP;
			break;
		}
		move(direction);
		printBoard();
	}
	cout << "Game Over!" << endl;
}