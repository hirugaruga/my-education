#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

std::vector<std::string> subsequence(long long n) {
	std::vector<std::string> v;
	for (long long i = 1; i <= n; ++i) {
		v.push_back(std::to_string(i));
	}
	std::sort(v.begin(), v.end());
	return v;
}

int main() {
	long long k;
	long long m;
	std::cin >> k >> m;
	if (k > m) {
		std::cout << 0;
	} else {
		long long r = 0;
		while (k < std::pow(10,r)) {
			++r;
		}
		std::vector<std::string> v = subsequence(r);
		long long ans;
		ans = r + (m - std::find(v.begin(), v.end(),k));
		std::cout << ans;
	}
}