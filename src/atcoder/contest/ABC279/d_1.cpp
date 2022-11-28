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
}

// 三分探索

int32_t main(void)
{
  uint64_t a = 0;
  uint64_t b = 0;
  uint64_t l = 0;
  uint64_t r = 1e18;
  double ans = 0;

  cin >> a >> b;

  auto f = [&](uint64_t n) {
    return (double)(a / sqrt(n + 1.0) + (double)n * b);
  };

  while (r - l > 2) {
    uint64_t m1 = (l * 2 + r) / 3;
    uint64_t m2 = (l + r * 2) / 3;
    if (f(m1) > f(m2)) l = m1;
    else r = m2;
  }
    
  ans = std::min({f(l), f(l + 1), f(r)});
  cout << std::fixed << std::setprecision(10) << ans << endl;

  return 0;
}