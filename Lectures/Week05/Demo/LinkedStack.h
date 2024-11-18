#pragma once
#include <list>

class LinkedStack
{
private:
	std::list<int> data;
public:
	void push(int num);
	void pop();
};

