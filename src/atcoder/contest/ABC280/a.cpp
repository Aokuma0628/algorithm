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
}

int32_t main(void)
{
  int32_t ans = 0;
  int32_t h = 0;
  int32_t w = 0;

  cin >> h >> w;
  for (int32_t i = 0; i < h; i++) {
    for (int32_t j = 0; j < w; j++) {
      char s = 0;
      cin >> s;
      if (s == '#') ans++;
    }
  }

  cout << ans << endl;

  return 0;
}