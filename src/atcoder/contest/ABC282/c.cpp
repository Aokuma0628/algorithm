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

  const int32_t STRING_MAX = 200'000 + 4;
  const char COMMA = ',';
  const char QUOT = '"';
  const char PERIOD = '.';
}

int32_t main(void)
{
  int32_t n = 0;
  char s[STRING_MAX] = { 0 };
  char ans[STRING_MAX] = { 0 };
  bool in_quot = false;

  cin >> n;
  cin >> s;

  strcpy(ans, s);

  for (int32_t i = 0; i < n; i++) {
    if (s[i] == QUOT) {
      if (in_quot) {
        in_quot = false;
      }
      else {
        in_quot = true;
      }
    }
    else if (s[i] == COMMA) {
      if (!in_quot) {
        ans[i] = PERIOD;
      }
    }
    else {
      //nothing
    }
  }

  cout << ans << endl;

  return 0;
}