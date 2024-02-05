#include <cstring>
#include <iostream>

class String {
 public:
  String();
  String(const char* s);
  String(size_t n, char c);
  String(const String& s);
  ~String();
 private:
  char* str_ = nullptr;
  size_t sz_ = 0;
};

String::~String() {
  delete[] str_;
}
String::String(size_t n, char c) : str_(new char[n]), sz_(n) {
  memset(str_, c, n);
}
String::String(const String& s) : str_(new char[s.sz_]), sz_(s.sz_) {
  memcpy(str_, s.str_, sz_);
}

int main() {
  String s(5, '2');
  }