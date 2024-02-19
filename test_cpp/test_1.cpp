#include <iostream>
#include <string>

int main() {
	long long t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		long long n;
		std::string s;
		std::cin >> n >> s;
		if (s.find_last_of('B') == s.find_first_of('B') && s.find_first_of('B') != -1 ) {
			std::cout << 1 << '\n';
		} else if (s.find_last_of('B') == -1) {
			std::cout << 0;
		} else {
			std::cout << s.find_last_of('B') - s.find_first_of('B') + 1 << '\n';
		}
	}
}