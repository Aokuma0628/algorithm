#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  const uint32_t DIVISOR = 1'000'000'007;
}




namespace {

 
  void main_logic(
    uint32_t n,
    uint32_t l
  )
  {
    vector<uint32_t> dp(n + 1);
    
    dp[0] = 1;

    for (uint32_t i = 1; i <= n; i++) {
      if (i < l) {
        dp[i] = dp[i - 1];
      }
      else {
        dp[i] = (dp[i - 1] + dp[i - l]) % DIVISOR;
      }
    }

    cout << dp[n] << endl;

    return;
  }
}

int32_t main(void)
{
  uint32_t n,l = 0;

  cin >> n >> l;

  main_logic(n, l);

  return 0;
}