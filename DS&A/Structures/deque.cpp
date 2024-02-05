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
}

template<typename T>
T Deque<T>::pop_back() {
  if (size_ == 0) {
	std::cerr << "Deque::pop_back: empty deque";
  }
  Node* tmp = tail_;
  if (size_ != 0) {
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
