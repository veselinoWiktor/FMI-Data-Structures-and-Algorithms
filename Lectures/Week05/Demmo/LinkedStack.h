//
// Created by vvese on 11/5/2024.
//

#pragma once
#include <list>

struct LinkedStack {
private:
  std::list<int> data;
public:
  void push(int number);
  void pop();
};