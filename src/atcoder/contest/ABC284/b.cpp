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

  const int32_t MAX = 100 + 4;
}

int32_t main(void)
{
  int32_t t = 0;

  cin >> t;

  for (int32_t i = 0; i < t; i++) {
    int32_t n = 0;
    int32_t cnt = 0;

    cin >> n;
    for (int32_t j = 0; j < n; j++) {
      int32_t a = 0;
      cin >> a;
      if (a % 2 == 1) cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}