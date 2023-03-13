#pragma once
#include <iostream>
using namespace std;
#include <deque>
class Snake
{
public:
	void push_back(int x, int y);

	void push_front(int x, int y);

	void pop_back();

	pair<int, int> get_tail();

	pair<int, int> get_Head();

	bool isSelfCrash(int x, int y);

private:
	deque<pair<int, int>> deq;
};