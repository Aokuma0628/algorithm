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

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  const uint64_t MAX_ANSWER = 1'000'000'000'000'000'000;
}

namespace {
  uint64_t calc_greatest_common_divisor(
    uint64_t x,
    uint64_t y 
  )
  {
    // Euclidean Algorithm
    while (x != 0 && y != 0) {
      if (x >= y) {
        x = x % y;
      }
      else {
        y = y % x;
      }
    }
    return (x != 0) ? x : y;
  }

  uint64_t calc_least_common_multiple(
    uint64_t x,
    uint64_t y
  )
  {
    /* ２数x,y の最大公約数を G、最小公倍数を L とおくと下式が成り立つ。
        L = xy/G
    */
    uint64_t max_divisor = calc_greatest_common_divisor(x, y);

    if (x / max_divisor > UINT64_MAX / y) {
      return 0;
    }
    else {
      return x / max_divisor * y;
    }
  }

  void main_logic(
    uint64_t a,
    uint64_t b
  )
  {
    uint64_t ans = 0;

    ans = calc_least_common_multiple(a, b);
    if (ans == 0 || ans > MAX_ANSWER) {
      cout << "Large" << endl;
    }
    else {
      cout << ans << endl;
    }

    return;
  }
}

int32_t main(void)
{
  uint64_t a,b = 0;

  std::cin >> a >> b;

  main_logic(a, b);

  return 0;
}