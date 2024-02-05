#include<iostream>
#include<vector>

int solve(int n, std::vector<int>& dp) {
  if (n < 0) {
	return 0;
  }
  if (n == 0) {
	return 1;
  }
  if (dp[n] != -1) {
	return dp[n];
  }
  dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
  return dp[n];
}
int main() {
  int n;
  std::cin >> n;
  std::vector<int> dp(n + 1, -1);
  std::cout << solve(n, dp);
}