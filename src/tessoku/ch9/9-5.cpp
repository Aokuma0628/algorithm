// A65 木に対する動的計画法

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t n = 0;
  int32_t dp[NUM_MAX] = { 0 };
  std::vector<int32_t> g[NUM_MAX];

  cin >> n;
  for (int32_t i = 2; i <= n; i++) {
    int32_t a = 0;
    cin >> a;
    g[a].emplace_back(i);
  }

  for (int32_t i = n; i >= 1; i--) {
    dp[i] = 0;
    for (int32_t j = 0; j < (int32_t)g[i].size(); j++) {
      dp[i] += dp[g[i][j]] + 1;
    }
  }

  for (int32_t i = 1; i <= n; i++) {
    if (i >= 2) cout << " ";
    cout << dp[i];
  }

  return 0;
}