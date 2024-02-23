#include <cstring>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

class String {
 public:
	String();
	String(const char* s);
	String(char c);
	String(size_t n, char c);
	String(const String& s);
	String(std::initializer_list<char> lst);
	~String();
	String& operator=(String s);
	String& operator+=(char c);
	String& operator+=(const String&);
	friend String operator+(const String& left, const String& right);
	friend std::ostream& operator<<(std::ostream& out, const String& s);
	char& operator[](size_t pos) const;
	char& front();
	char& back();
	size_t length() const;
	void push_back(char c);
	char pop_back();
	void swap(String& s);
 private:
	size_t sz_;
	char* str_;
};

String::String() : sz_(0), str_(nullptr) {}

String::String(const char* s) : sz_(std::strlen(s)), str_(new char[std::strlen(s)]) {
	memcpy(str_, s, sz_);
}

String::String(char c) : sz_(1), str_(new char[1]) {
	memset(str_, c, 1);
}

String::String(size_t n, char c) : sz_(n), str_(new char[n]) {
	memset(str_, c, n); //memory with that adress, with what, how much
}

String::String(const String& s) : sz_(s.sz_), str_(new char[s.sz_]) {
	memcpy(str_, s.str_, sz_); // where, whom, how much
}

String::String(std::initializer_list<char> lst) : sz_(lst.size()), str_(new char[lst.size()]) {
	std::copy(lst.begin(), lst.end(), str_);
}

String::~String() {
	delete[] str_;
}

bool operator==(const String& left, const String& right) {
	if (left.length() != right.length()) {
		return false;
	} else {
		size_t it = 0;
		while (it <= left.length()) {
			if (left[it] != right[it]) {
				return false;
			}
			++it;
		}
		return true;
	}
}

char& String::operator[](size_t pos) const {
	if (pos > sz_) {
		std::cerr << "String::operator[] : string index out of range\n";
		exit(0);
	}
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

size_t String::length() const {
	return sz_;
}

void String::push_back(char c) {

}

char& String::front() {
	return *this->str_;
}

char& String::back() {
	return *(this->str_ + sz_);
}

String operator+(const String& left, const String& right) {
	String temp;
	delete[] temp.str_;
	temp.sz_ = left.sz_ + right.sz_;
	temp.str_ = new char[temp.sz_];
	std::strcpy(temp.str_, std::strcat(left.str_, right.str_));
	return temp;
}

String& String::operator+=(char c) {}

String& String::operator+=(const String& other) {
	if (other.sz_) {
		size_t size = sz_ + other.sz_;
		char* buff = new char[size + 1];
		strcpy(buff, str_);
		strcat(buff, other.str_);
		delete[] str_;
		str_ = buff;
		sz_  = size;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
	for (size_t i = 0; i < s.sz_; ++i) {
		out << *(s.str_ + i);
	}
	return out;
}
std::istream& operator>>(std::istream& is, String& s) {
	char* buff = new char[1000];
	memset(&buff[0], 0, sizeof(buff) / sizeof(buff[0]));
	is >> buff;
	s = String{buff};
	delete[] buff;
	return is;
}

void String::swap(String& s) {
	std::swap(sz_, s.sz_);
	std::swap(str_, s.str_);
}

int main() {
	String s = 's';
	String ss = "11111";
	s = s + ss;
	cout << s
	;
}