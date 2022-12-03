#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  const int32_t COUNT_MAX = 10 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  int32_t s[COUNT_MAX] = { 0 };
  int64_t ans[COUNT_MAX] = { 0 };

  cin >> n;
  for (int32_t i = 1; i <= n; i++) {
    cin >> s[i];
    ans[i] = s[i] - s[i - 1];
  }

  for (int32_t i = 1; i <= n; i++) {
    if (i >= 2) cout << " ";
    cout << ans[i];
  }

  return 0;
}