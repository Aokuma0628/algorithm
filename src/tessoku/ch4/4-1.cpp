// A15 チャレンジ問題

#include <iostream>
#include <cstdint>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;

int main() {
  uint32_t n = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t b[NUM_COUNT] = { 0 };
  uint32_t dp[NUM_COUNT] = { 0 };

  cin >> n;
  for (uint32_t i = 2; i <= n; i++) cin >> a[i];
  for (uint32_t i = 3; i <= n; i++) cin >> b[i];

  dp[1] = 0;
  dp[2] = a[2];

  for (uint32_t i = 3; i <= n; i++) {
    dp[i] = std::min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
  }

  cout << dp[n] << endl;

  return 0;
}