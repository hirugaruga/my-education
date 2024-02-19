#include <cstring>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

class String {
 public:
	String();
	String(const char* s);
	String(size_t n, char c);
	String(const String& s);
	String(std::initializer_list<char> lst);
	~String();
	String& operator=(String s);
	bool operator==(const String& left, const String& right);
	//bool operator==(const String& left, const char*);
	char operator[](const String& s, size_t pos);
	String& operator+(const String& left, const String& right);
	String& operator+=(char c);
	String& operator+=(const String&);
	char& front();
	char& back();
	size_t length();
	void push_back(char c);
	char pop_back();
	void swap(String& s);
 private:
	size_t sz_;
	char* str_;
};

String::String() : cz_(0), str_(nullptr) {}

String::~String() {
	delete[] str_;
}

String::String(size_t n, char c) : str_(new char[n]), sz_(n) {
	memset(str_, c, n); //memory with that adress, with what, how much
}

String::String(const String& s) : str_(new char[s.sz_]), sz_(s.sz_) {
	memcpy(str_, s.str_, sz_); // where, whom, how much
}

String::String(std::initializer_list<char> lst) : str_(new char[lst.size()]), sz_(lst.size()) {
	std::copy(lst.begin(), lst.end(), str_);
}

void String::swap(String& s) {
	std::swap(sz_, s.sz_);
	std::swap(str_, s.str_);
}

bool String::operator==(const String& left, const String& right) {
	if (left.sz_ != right.sz_) {
		return false;
	} else {
		size_t it = 0;
		while (it <= left.sz_) {
			if (left.str_ + it != right.str_ + it) {
				return false;
			}
		}
		return true;
	}
}

char String::operator[](size_t pos) {
	return *(this->str_ + pos);
}

// idioma copy-and-swap
String& String::operator=(String s) {
	swap(s);
	/*this->~String(); UB
	delete[] str_;
	sz_ = s.sz_;
	str_ = new char[sz_];
	std::copy(s.str_, s.str_ + cz_, str_);*/
	return *this;
}

size_t String::length() {
	return this->sz_;
}
/*
void String::push_back(char c) {

}
*/
char& String::front() {
	return *this->str_;
}

char& String::back() {
	return *(this->str_ + sz_);
}

String& String::operator+(const String& left, const String& right) {
	String temp;
	delete[] temp.str_;
	temp.sz_ = left.sz_ + right.cz_;
	temp.str_ = new char[sz_];
	std::strcpy(temp.str_, std::strcat(left.str_, right.str_));
	return temp;
}

String& String::operator+=(char c) {

}
String& String::operator+=(const String&) {}

int main() {
	String s(5, '2');
}
