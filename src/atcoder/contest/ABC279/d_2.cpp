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

// 微分

int32_t main(void)
{
  uint64_t a = 0;
  uint64_t b = 0;
  uint64_t min = 0;
  double ans = 0;


  cin >> a >> b;

  auto f = [&](uint64_t n) {
    return (double)(a / sqrt(n + 1.0) + (double)n * b);
  };

  min = std::pow((double)(a / (2 * b)), 2.0 / 3.0) - 1;

  ans = f(min);

  for (uint64_t i = -5; i <=5; i++) {
    ans = std::min(ans, f(min + i));
  }

  ans = std::min({f(min - 1), f(min), f(min + 1)});
  cout << std::fixed << std::setprecision(10) << ans << endl;

  return 0;
}