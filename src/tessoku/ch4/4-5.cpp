// A20 二次元のDP 最長共通部分列問題

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;

const uint32_t STR_LEN = 2000 + 4;

int main() {
  std::string s;
  std::string t;
  size_t s_len = 0;
  size_t t_len = 0;
  uint32_t dp[STR_LEN][STR_LEN] = {{ 0 }};

  cin >> s;
  cin >> t;
  s_len = s.length();
  t_len = t.length();

  dp[0][0] = 0;
  for (uint32_t i = 0; i <= (uint32_t)s_len; i++) {
    for (uint32_t j = 0; j <= (uint32_t)t_len; j++) {
      if (i >= 1 && j >= 1 && s[i - 1] == t[j - 1]) {
        dp[i][j] = std::max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + 1});
      }
      else if (i >= 1 && j >= 1) {
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      }
      else if (i >= 1) {
        dp[i][j] = dp[i -1][j];
      }
      else if (j >= 1) {
        dp[i][j] = dp[i][j-1];
      }
      else {
        ; // dp[0][0]
      }
    }
  }

  cout << dp[s_len][t_len] << endl;

  return 0;
}