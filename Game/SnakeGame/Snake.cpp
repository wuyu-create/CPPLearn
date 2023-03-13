#include "Snake.h"

void Snake::pop_back()
{
	deq.pop_back();
}

bool Snake::isSelfCrash(int x, int y)
{
	for (int i = 0; i < deq.size() - 1; i++)
	{
		if (x == deq[i].first && y == deq[i].second)
		{
			return true;
		}
	}

	return false;
}

pair<int, int> Snake::get_tail()
{
	return deq.back();
}

pair<int, int> Snake::get_Head()
{
	return deq.front();
}

void Snake::push_back(int x, int y)
{
	deq.push_back(make_pair(x, y));
}

void Snake::push_front(int x, int y)
{
	deq.push_front(make_pair(x, y));
}