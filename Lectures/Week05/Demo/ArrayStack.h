#pragma once

class ArrayStack
{
private:
	int* data;
	int capacity;
	int top; // индекс на последния елемент на стека
public:
	ArrayStack(int capacity);

	void push(int number);
	void pop();
	int peek() const;
	bool isEmpty() const;
};

