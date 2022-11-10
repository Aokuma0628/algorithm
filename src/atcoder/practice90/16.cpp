#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>

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
  bool sort_func(
    int32_t a,
    int32_t b
  )
  {
    if (a < b) {
      return false;
    }
    else {
      return true;
    }
  }

  void main_logic(
    int32_t n,
    std::array<int32_t, NUM_COUNT> coin
  )
  {
    int32_t num = 0;
    int32_t min_num = 9999;
    int32_t i, j;

    std::sort(coin.begin(), coin.end(), sort_func);

    for (i = n / coin[0]; i >= 0; i--) {
      int32_t remain = n - (coin[0] * i);

      if (remain == 0) {
        num = i;
        if (min_num > num) min_num = num;
      }

      if (coin[1] > remain && coin[2] > remain) {
        continue;
      }

      for (j = remain / coin[1]; j >= 0; j--) {
        int32_t mid_rem = remain - (coin[1] * j);
        int32_t min_rem = mid_rem % coin[2];

        if (mid_rem == 0) {
          num = i + j;
          if (min_num > num) min_num = num;
        }
        if (min_rem == 0) {
          num = i + j + (mid_rem / coin[2]);
          if (min_num > num) min_num = num;
        }
      }
    }

    cout << min_num << endl;

    return;
  }
}


int32_t main(void)
{
  std::array<int32_t, NUM_COUNT> arr = { 0 };
  int32_t num = 0;
  int32_t i = 0;

  std::cin >> num;
  for (i = 0; i < NUM_COUNT; i++) {
    std::cin >> arr[i];
  }

  main_logic(num, arr);

  return 0;
}