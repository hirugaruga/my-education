#include "iostream"
#include "string"

class Stack {
 public:
  Stack();
  void push(char elem);
  void pop();
  char back();
  int size();
 private:
  struct Node {
	char val;
	Node* next;
  };
  Node* top_;
  int size_;
};

Stack::Stack() {
  top_ = nullptr;
  size_ = 0;
}
void Stack::push(char elem) {
  Node* tmp = new Node;
  tmp->val = elem;
  tmp->next = top_;
  top_ = tmp;
  ++size_;
}
void Stack::pop() {
  Node* tmp = top_;
  top_ = top_->next;
  --size_;
  delete tmp;
}
int Stack::size() {
  return size_;
}
char Stack::back() {
  return top_->val;
}
char skobka(char elem) {
  if (elem == '(') {
	return ')';
  } else {
	return elem + 2;
  }
}
int main() {
  std::string s;
  Stack stack;
  getline(std::cin, s);
  for (int i = 0; i < s.size(); ++i) {
	if (stack.size() > 0 && skobka(stack.back()) == s[i]) {
	  stack.pop();
	} else {
	  stack.push(s[i]);
	}
  }
  if (stack.size() == 0) {
	std::cout << "yes";
  } else {
	std::cout << "no";
  }
}