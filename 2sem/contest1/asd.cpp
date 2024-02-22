#include <iostream>

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

/****************************main**********************************************/
int main() {
	Deque<int> a;
	Deque<int> b;
	Deque<int> c;
	int n;
	int steps = 0;
	bool flag = true;
	std::cin >> n;
	int nn = n;
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		b.push_back(k);
	}
	while (flag && a.size() != nn) {
		if (b.size() != 0 && b.front() == n) {
			a.push_front(b.pop_front());
			++steps;
			--n;
		} else if (c.size() != 0 && c.front() == n) {
			a.push_front(c.pop_front());
			++steps;
			--n;
		} else if (b.size() == 0 && c.front() != n) {
			flag = false;
		} else if (b.front() != n && (c.size() == 0 || c.front() != n)) {
			c.push_front(b.pop_front());
			++steps;
		}
	}
	if (flag) {
		std::cout <<
							steps;
	} else {
		std::cout << 0;
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