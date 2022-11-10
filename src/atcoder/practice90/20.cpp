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
    NUM_COUNT = 3,
  };
}

namespace {
  void main_logic(
    int64_t a,
    int32_t b,
    int32_t c
  )
  {
    int64_t val = c;
    int32_t i = 0;

    for (i = 1; i < b; i++) {
      val *= c;
      if ((i + 1) != b && val * 2 > INT64_MAX) {
        return;
      }
    }

    if (a < val) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }

    return;
  }
}


int32_t main(void)
{
  int64_t a = 0;
  int32_t b,c = 0;

  std::cin >> a >> b >> c;
  main_logic(a, b, c);

  return 0;
}