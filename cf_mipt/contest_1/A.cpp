#include <string>
#include <iostream>
#include <map>

class Stack {
 public:
  Stack();
  void push(int elem);
  void pop();
  void back();
  void size();
  void clear();
 private:
  struct Node {
	int val;
	Node* next;
  };
  Node* top_;
  int size_;
};

Stack::Stack() {
  top_ = nullptr;
  size_ = 0;
}

void Stack::push(int elem) {
  Node* tmp = new Node;
  tmp->val = elem;
  tmp->next = top_;
  top_ = tmp;
  ++size_;
  std::cout << "ok" << '\n';
}

void Stack::pop() {
  if (size_ == 0) {
	std::cout << "error" << '\n';
  } else {
	Node* tmp = top_;
	top_ = top_->next;
	--size_;
	int val = tmp->val;
	std::cout << val << '\n';
	delete tmp;
  }
}

void Stack::back() {
  if (size_ == 0) {
	std::cout << "error" << '\n';
  } else {
	std::cout << top_->val << '\n';
  }
}

void Stack::size() {
  std::cout << size_ << '\n';
}
void Stack::clear() {
  while (size_ != 0) {
	Node* tmp = top_;
	top_ = top_->next;
	--size_;
	delete tmp;
  }
  top_ = nullptr;
  std::cout << "ok" << '\n';
}
int main() {
  std::map<std::string, int> mapping;
  mapping["push"] = 1;
  mapping["pop"] = 2;
  mapping["back"] = 3;
  mapping["size"] = 4;
  mapping["clear"] = 5;
  std::string input;
  int a;
  Stack stack;
  std::cin >> input;
  while (input != "exit") {
	switch (mapping[input]) {
	  case 1: std::cin >> a;
		stack.push(a);
		break;
	  case 2: stack.pop();
		break;
	  case 3: stack.back();
		break;
	  case 4: stack.size();
		break;
	  case 5: stack.clear();
		break;
	}
	std::cin >> input;
  }
  std::cout << "bye" << "\n";
}