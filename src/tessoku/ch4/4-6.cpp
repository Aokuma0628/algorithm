// A21 二次元のDP 区間DP

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUMBER_MAX = 2000 + 4;

int main() {
  uint32_t n = 0;
  uint32_t p[NUMBER_MAX] = { 0 };
  uint32_t a[NUMBER_MAX] = { 0 };
  uint32_t dp[NUMBER_MAX][NUMBER_MAX] = {{ 0 }};

  cin >> n;
  for (uint32_t i = 1; i <= n; i++) cin >> p[i] >> a[i];

  // (n-2)は(r-l)がn-1の場合は何も取っていないのでポイントが0に決まっているため
  for (int32_t diff = n - 2; diff >= 0; diff--) {
    for (uint32_t l = 1; l <= n - diff; l++) {
      uint32_t r = l + diff;

      // (l-1)番目のブロックが取り除かれた場合の得点
      uint32_t score1 = 0;
      // p[l-1]が保持するブロックがまだl~r間に残っていれば点数を得る
      if (l <= p[l - 1] && p[l - 1] <= r) score1 = a[l - 1];

      // (r+1)番目のブロックが取り除かれた場合の得点
      uint32_t score2 = 0;
      if (l <= p[r + 1] && p[r + 1] <= r) score2 = a[r + 1];

      dp[l][r] = std::max(dp[l - 1][r] + score1, dp[l][r + 1] + score2);

    }
  }

  uint32_t ans = 0;
  for (uint32_t i = 1; i <= n; i++) ans = std::max(ans, dp[i][i]);

  cout << ans << endl;

  return 0;
}