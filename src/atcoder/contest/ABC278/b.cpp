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

  const uint32_t NUM_COUNT = 200 + 4;
}

bool is_hour (
  int32_t hour
)
{
  if (hour >= 0 && hour <= 23) {
    return true;
  }
  return false;
}

bool is_minute (
  int32_t minute
)
{
  if (minute >= 0 && minute <= 59) {
    return true;
  }
  return false;
}

int32_t main(void)
{
  int32_t h, m = 0;
  int32_t a,b,c,d = 0;
  int32_t ans_h, ans_m = 0;

  cin >> h >> m;
  a = h / 10;
  b = h % 10;
  c = m / 10;
  d = m % 10;

  while (true) {
    int32_t chg_b = c;
    int32_t chg_c = b;
    int32_t hour = a * 10 + chg_b;
    int32_t minute = chg_c * 10 + d;
    
    if (is_hour(hour) && is_minute(minute)) break;

    d++;
    if (d == 10) {
      d = 0;
      c++;
    }
    if (c == 6) {
      c = 0;
      b++;
    }
    if (a <= 1 && b == 10) {
      b = 0;
      a++;
    }
    if (a == 2 && b == 4) {
      a = 0;
      b = 0;
    }
  }

  ans_h = a * 10 + b;
  ans_m = c * 10 + d;

  cout << ans_h << " " << ans_m << endl;

  return 0;
}