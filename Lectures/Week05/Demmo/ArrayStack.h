//
// Created by vvese on 11/5/2024.
//

#pragma once

class ArrayStack {
private:
  	int* data;
    int capacity;
    int top; // индекс на последния елемент на стека

public:
	ArrayStack(int capacity) {
          this->capacity = capacity;
          this->data = new int[capacity];
          top = -1;
    }
};