#include "Menu.h"
Menu::Menu()
{
	printMenu();
}
void Menu::startGame()
{
	SnakeGame snake;
	while (1)
	{
		if (snake.is_GameOver())
			break;

		snake.control();
		Sleep(1000);
	}
	system("cls");
	cout << "ʧ��" << endl;
	system("pause");
	printMenu();

}
void Menu::printMenu()
{
	cout << "############ Snake Game ############" << endl;
	cout << "############ 1 START Game ############" << endl;
	cout << "############ 2  Out Game  ############" << endl;

	char ch;
	ch = _getch();

	if (ch == '1')
	{
		startGame();
	}
	else if (ch == '2')
	{
		system("pause");
		exit(0);
	}
	else
	{
		cout << "������ 1 �� 2" << endl;
		system("pause");
		printMenu();
	}
}