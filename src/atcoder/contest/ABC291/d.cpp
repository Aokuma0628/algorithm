#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stack>
#include <queue>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 200'000 + 4;
  const int32_t MOD = 998'244'353;
}

int32_t main(void)
{
  int32_t n = 0;
  int32_t a[NUM_MAX] = { 0 };
  int32_t b[NUM_MAX] = { 0 };
  int64_t dp[NUM_MAX][2] = { 0 };
  cin >> n;

  for (int32_t i = 0; i < n; i++ ) cin >> a[i] >> b[i];

  dp[0][0] = 1;
  dp[0][1] = 1;

  for (int32_t i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) dp[i][0] += dp[i - 1][0] % MOD;
    if (a[i] != b[i - 1]) dp[i][0] += dp[i - 1][1] % MOD;
    if (b[i] != a[i - 1]) dp[i][1] += dp[i - 1][0] % MOD;
    if (b[i] != b[i - 1]) dp[i][1] += dp[i - 1][1] % MOD; 
  }

  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl; 

  return 0;
}