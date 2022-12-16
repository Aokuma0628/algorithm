// A30 余りの計算 割り算

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 2'000 + 9;

int main() {
  int32_t n = 0;
  int32_t a[NUM_MAX] = { 0 };
  int32_t dp[NUM_MAX][NUM_MAX] = {{ 0 }};

  cin >> n;
  for (int32_t i = 1; i <= n; i++) cin >> a[i];

  for (int32_t i = 1; i <= n; i++) dp[n][i] = a[i];

  for (int32_t i = n - 1; i >= 1; i--) {
    for (int32_t j = 1; j <= i; j++) {
      if (i % 2 == 1) {
        dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j + 1]);
      }
      else {
        dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]);
      }
    }
  }

  cout << dp[1][1] << endl;

  return 0;
}