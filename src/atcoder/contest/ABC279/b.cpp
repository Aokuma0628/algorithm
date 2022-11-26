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

  const uint32_t STRING_LENGTH_MAX = 100 + 4;
}

int32_t main(void)
{
  char s[STRING_LENGTH_MAX] = { 0 };
  char t[STRING_LENGTH_MAX] = { 0 };

  char *ans = NULL;

  cin >> s;
  cin >> t;

  ans = std::strstr(s, t);

  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}