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
  std::string s;
  uint32_t ans = 0;

  cin >> s;

  for (uint32_t i = 0; i < s.size(); i++) {
    if (s[i] == 'w') {
      ans += 2;
    }
    else {
      ans += 1;
    }
  }

  cout << ans << endl;

  return 0;
}