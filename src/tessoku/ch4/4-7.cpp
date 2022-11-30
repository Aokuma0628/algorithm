// A22 遷移形式の工夫

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUMBER_MAX = 100'000 + 4;

int main() {
  int32_t n = 0;
  int32_t a[NUMBER_MAX] = { 0 };
  int32_t b[NUMBER_MAX] = { 0 };
  int32_t dp[NUMBER_MAX] = { 0 };

  cin >> n;
  for (int32_t i = 1; i <= n - 1; i++) cin >> a[i];
  for (int32_t i = 1; i <= n - 1; i++) cin >> b[i];

  dp[1] = 0;
  // a,bにないマスは大きな負数で初期化しておくため
  for (int32_t i = 2; i <= n; i++) dp[i] = -1'000'000'000;

  for (int32_t i = 1; i <= n - 1; i++) {
    dp[a[i]] = std::max(dp[a[i]], dp[i] + 100);
    dp[b[i]] = std::max(dp[b[i]], dp[i] + 150);
  }
  
  cout << dp[n] << endl;

  return 0;
}