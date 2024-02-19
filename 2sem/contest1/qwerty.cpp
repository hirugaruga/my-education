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
long long search(std::vector<std::string> v, std::string k) {
	for (long long it = 0; it < v.size(); ++it) {
		if (k == v[it]) {
			return it;
		}
	}
}

int main() {
	long long k;
	long long m;
	std::cin >> k >> m;
	long long r = 0;
	while (k > std::pow(10, r)) {
		++r;
	}
	std::vector<std::string> v = subsequence(std::pow(10, r));
	/*for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << ' ';
	}
	 */
	long long ans;
	ans = search(v, std::to_string(k));
	std::cout << std::pow(10, r) - m + ans - 1;
}