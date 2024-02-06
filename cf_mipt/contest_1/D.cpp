#include<iostream>

template<typename T>
class Deque {
 public:
  Deque();
  void push_front(T val);
  void push_back(T val);
  T pop_front();
  T pop_back();
  void clear();
  T front() const;
  T back() const;
  int size() const;
 private:
  struct Node {
	T val;
	Node* next;
	Node* prev;
  };
  Node* head_;
  Node* tail_;
  int size_;
};

/****************************MAIN**********************************************/
void balance(Deque<int>& left, Deque<int>& right) {
  while (left.size() > right.size()) {
	int tmp = left.pop_front();
	right.push_back(tmp);
  }
}

int main() {
  Deque<int> left;
  Deque<int> right;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
	char c;
	int num;
	std::cin >> c;
	if (c == '+') {
	  std::cin >> num;
	  left.push_back(num);
	  balance(left, right);
	} else if (c == '-') {
	  std::cout << right.pop_front() << '\n';
	  balance(left, right);
	} else if (c == '*') {
	  std::cin >> num;
	  left.push_front(num);
	  balance(left, right);
	}
  }
}

/****************************DEQUE*********************************************/

template<typename T>
Deque<T>::Deque() {
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

template<typename T>
void Deque<T>::push_front(T val) {
  Node* tmp = new Node;
  tmp->val = val;
  tmp->next = nullptr;
  if (size_ == 0) {
	tail_ = tmp;
	tmp->prev = nullptr;
  } else {
	head_->next = tmp;
	tmp->prev = head_;
  }
  head_ = tmp;
  ++size_;
}
template<typename T>
void Deque<T>::push_back(T val) {
  Node* tmp = new Node;
  tmp->val = val;
  tmp->prev = nullptr;
  if (size_ == 0) {
	head_ = tmp;
	tmp->next = nullptr;
  } else {
	tail_->prev = tmp;
	tmp->next = tail_;
  }
  tail_ = tmp;
  ++size_;
}

template<typename T>
T Deque<T>::pop_back() {
  if (size_ == 0) {
	std::cerr << "Deque::pop_back: empty deque";
  }
  Node* tmp = tail_;
  if (size_ != 1) {
	tail_ = tmp->next;
	tmp->next->prev = nullptr;
  } else {
	tail_ = nullptr;
	head_ = nullptr;
  }
  T val = tmp->val;
  delete tmp;
  --size_;
  return val;
}

template<typename T>
T Deque<T>::pop_front() {
  if (size_ == 0) {
	std::cerr << "Deque::pop_front: empty deque";
  }
  Node* tmp = head_;
  if (size_ != 1) {
	head_ = tmp->prev;
	head_->next = nullptr;
  } else {
	tail_ = nullptr;
	head_ = nullptr;
  }
  T val = tmp->val;
  delete tmp;
  --size_;
  return val;
}
template<typename T>
void Deque<T>::clear() {
  while (size_ != 0) {
	Node* tmp = tail_;
	tail_ = tmp->next;
	delete tmp;
	--size_;
  }
  head_ = nullptr;
  tail_ = nullptr;
}

template<typename T>
T Deque<T>::front() const {
  return head_->val;
}

template<typename T>
T Deque<T>::back() const {
  return tail_->val;
}

template<typename T>
int Deque<T>::size() const {
  return size_;
}