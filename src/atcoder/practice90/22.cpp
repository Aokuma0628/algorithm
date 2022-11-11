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
}

namespace {
  uint64_t calc_greatest_common_divisor(
    uint64_t x,
    uint64_t y 
  )
  {
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


  void main_logic(
    uint64_t a,
    uint64_t b,
    uint64_t c
  )
  {
    uint64_t ans = 0;
    uint64_t divisor_ab = 0;
    uint64_t divisor_abc = 0;
    

    divisor_ab = calc_greatest_common_divisor(a,b);
    divisor_abc = calc_greatest_common_divisor(c, divisor_ab);

    ans = (a / divisor_abc - 1) +
          (b / divisor_abc - 1) +
          (c / divisor_abc - 1);

    cout << ans << endl;

    return;
  }
}


int32_t main(void)
{
  uint64_t a,b,c = 0;

  std::cin >> a >> b >> c;
  main_logic(a, b, c);

  return 0;
}