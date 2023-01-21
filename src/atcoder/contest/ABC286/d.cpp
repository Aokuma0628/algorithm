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

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  const int32_t NUM_MAX = 50 + 4;
  const int32_t PRICE_MAX = 10'000 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  int32_t x = 0;
  int32_t a[NUM_MAX] = { 0 };
  int32_t b[NUM_MAX] = { 0 };

  bool dp[NUM_MAX][PRICE_MAX] = { false };

  cin >> n >> x;

  for (int32_t i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  dp[0][0] = true;
  for (int32_t i = 1; i <= x; i++) dp[0][i] = false;

  for (int32_t i = 1; i <= n; i++) {
    for (int32_t j = 0; j <= x; j++) {
      for (int32_t k = 1; k <= b[i]; k++) {
        if ((a[i] * k) > j) {
          if (dp[i - 1][j] == true || dp[i][j] == true) dp[i][j] = true;
          else dp[i][j] = false;
        }
        else {
          if (dp[i - 1][j] == true || dp[i - 1][j - (a[i] * k)] == true || dp[i][j] == true) dp[i][j] = true;
          else dp[i][j] = false;
        }
      }
    }
  }

  if (dp[n][x] == true) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}