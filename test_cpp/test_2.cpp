#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sequentialDigits(int low, int high) {
  std::string c = "123456789";
  std::vector<int> a;

  for (int i = 0; i < c.size(); i++) {
	for (int j = i + 1; j <= c.size(); j++) {
	  int curr = std::stoi(c.substr(i, j - i));
	  if (curr <= high && curr >= low) {
		a.push_back(curr);
	  }
	}
  }
  std::sort(a.begin(), a.end());
  return a;
}

  int main() {
	int low;
	int high;
	std::cin >> low >> high;
	std::vector<int> ans = sequentialDigits(low, high);
	for (auto x : ans) {
	  std::cout << x << ' ';
	}
  }