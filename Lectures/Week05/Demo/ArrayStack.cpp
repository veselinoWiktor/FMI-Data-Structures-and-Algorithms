#include "ArrayStack.h"

ArrayStack::ArrayStack(int capacity)
{
	this->capacity = capacity;
	this->data = new int[capacity]; // Заделя се масив с определена големина
	top = -1;
}

void ArrayStack::push(int number)
{
	if (top < capacity - 1) {
		top++;
		data[top] = number;
	}
}

void ArrayStack::pop()
{
	if (top > -1) {
		top--;
	}
}

int ArrayStack::peek() const
{
	if (top > -1) {
		return data[top];
	}

	return -1;
}

bool ArrayStack::isEmpty() const
{
	return top == -1;
}

