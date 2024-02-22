#include <iostream>

int main() {
	long long w;
	long long h;
	long long n;
	std::cin >> w >> h >> n;
	long long l = 0;
	long long r = std::max(w, h) * n;
	long long x;
	long long y;
	long long m;
	while (r - l > 1) {
		m = (l + r) / 2;
		x = m / w;
		y = m / h;
		if (x * y >= n) {
			r = m;
		} else {
			l = m;
		}
	}
	std::cout << r;
}