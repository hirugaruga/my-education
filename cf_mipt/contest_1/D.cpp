//
// Created by Timur on 21.12.2023.
//
#include <iostream>

class Queue {
 public:
  void push(int val);
  int size();
  int pop();
  bool empty();
 private:
  struct Node {
	int val;
	Node* next;
  };
  int size_;
  Node* prev_;
};