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
    NUM_COUNT = 10,
  };
}

namespace {
  void main_logic(
    uint32_t h,
    uint32_t w
  )
  {
    uint32_t ans = 0;

    if (h == 1 || w == 1) {
      ans = h * w;
    }
    else {
      ans = ((h + 1) / 2) * ((w + 1) / 2);
    }

    cout << ans << endl;
  }
}

int32_t main(void)
{
  uint32_t h,w = 0;

  std::cin >> h >> w;

  main_logic(h, w);

  return 0;
}