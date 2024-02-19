#include "iostream"


using std::cin;
using std::cout;

template<typename T>
size_t size(T& a) {
	return sizeof(a) / sizeof(*a);
}

template<typename T>
void merge(T& a, T& b, T& c) {
	int i = 0;
	int j = 0;
	int n = size(a);
	int m = size(b);
	while (i < n || j < m) {
		if (j == m || (i < n && a[i] <= b[j])) {
			c[i + j] = a[i];
		} else {
			c[i + j] = b[j];
		}
	}
}

template<typename T>
void mergesort(T& a) {
	mergesort();
}

int main() {
	int a[4];
	cout << size(a);
}