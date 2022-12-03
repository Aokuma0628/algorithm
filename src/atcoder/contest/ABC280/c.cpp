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

  const int32_t STRING_MAX = 500'000 + 4;
}

int32_t main(void)
{
  char s[STRING_MAX] = { 0 };
  char t[STRING_MAX] = { 0 };
  int32_t ans = 0;

  cin >> s;
  cin >> t;

  for (int32_t i = 0; i < STRING_MAX; i++) {
    if (s[i] != t[i]) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}