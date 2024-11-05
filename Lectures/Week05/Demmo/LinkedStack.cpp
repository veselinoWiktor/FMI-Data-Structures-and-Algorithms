//
// Created by vvese on 11/5/2024.
//

#include "LinkedStack.h"

void LinkedList::push(int value) {
    data.push_back(value);
}

void LinkedList::pop() {
  	data.pop_back();
}