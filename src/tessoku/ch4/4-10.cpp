// A25 チャレンジ問題

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUMBER_MAX = 30 + 4;

int main() {
  int32_t h = 0;
  int32_t w = 0;
  char c[NUMBER_MAX][NUMBER_MAX] = {{ 0 }};
  uint64_t dp[NUMBER_MAX][NUMBER_MAX] = {{ 0 }};

  cin >> h >> w;
  for (int32_t i = 1; i <= h; i++) {
    for (int32_t j = 1; j <= w; j++) cin >> c[i][j];
  }

  dp[1][1] = 1;
  for (int32_t i = 1; i <= h; i++) {
    for (int32_t j = 1; j <= w; j++) {
      if (i >= 2 && c[i - 1][j] == '.') dp[i][j] += dp[i - 1][j];
      if (j >= 2 && c[i][j - 1] == '.') dp[i][j] += dp[i][j - 1];
    }
  }

  cout << dp[h][w] << endl;

  return 0;
}