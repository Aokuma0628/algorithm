// A19 二次元のDP ナップザック問題

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100 + 4;
const uint32_t MAX_WEIGHT = 100'000 + 4;

int main() {
  uint32_t n,W = 0;
  uint32_t w[NUM_COUNT] = { 0 };
  uint32_t v[NUM_COUNT] = { 0 };
  int64_t dp[NUM_COUNT][MAX_WEIGHT];
  int64_t ans = 0;

  cin >> n >> W;
  for (uint32_t i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (uint32_t i = 0; i <= n; i++) {
    for (uint32_t j = 0; j <= W; j++) dp[i][j] = INT64_MIN;
  }

  dp[0][0] = 0;
  for (uint32_t i = 1; i <=n; i++) {
    for (uint32_t j = 0; j <= W; j++) {
      if (j < w[i]) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }

  for (uint32_t i = 0; i <= W; i++) {
    ans = std::max(ans, dp[n][i]);
  }
  cout << ans << endl;  

  return 0;
}