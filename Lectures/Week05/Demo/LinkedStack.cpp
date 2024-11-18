#include "LinkedStack.h"

void LinkedStack::push(int num)
{
	data.push_back(num);
}

void LinkedStack::pop()
{
	data.pop_back();
}
