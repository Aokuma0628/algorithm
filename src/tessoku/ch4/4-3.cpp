// A18 二次元のDP 部分和問題

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 60 + 4;
const uint32_t MAX_VALUE = 10'000 + 4;

int main() {
  uint32_t n = 0;
  uint32_t s = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  bool dp[NUM_COUNT][MAX_VALUE] = {{ 0 }};

  cin >> n >> s;
  for (uint32_t i = 1; i <= n; i++) cin >> a[i];

  // カードが0枚の時
  dp[0][0] = true;
  for (uint32_t i = 1; i <= s; i++) dp[0][s] = false;

  // カードが１枚以上の時
  for (uint32_t i = 1; i <= n; i++) {
    for (uint32_t j = 0; j <= s; j++) {
      // カード(i-1)の時点で合計がjであり、カードiを選ばない時がture もしくは
      // カード(i-1)の時点で合計が(j-Ai)であり、カードAiを選ぶとtrue

      if (j < a[i]) { // j-a[i]が0未満だと該当する値が存在しない
        if (dp[i - 1][j] == true) {
          dp[i][j] = true;
        }
        else {
          dp[i][j] = false;
        }
      }
      else {
        if (dp[i - 1][j] == true || dp[i - 1][j - a[i]] == true) {
          dp[i][j] = true;
        }
        else {
          dp[i][j] = false;
        }
      }
    }
  }

  if (dp[n][s] == true) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}