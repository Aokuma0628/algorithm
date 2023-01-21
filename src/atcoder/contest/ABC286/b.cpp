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

  const int32_t MAX = 1000 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  std::string s;

  cin >> n;
  cin >> s;

  for (int32_t i = 0; i < (int32_t)s.size(); i++) {
    if (i >= (int32_t)s.size() - 1) break;
    if (s[i] == 'n' && s[i+1] == 'a') {
      s.insert(i+1, "y");
    }
  }

  cout << s << endl;

  return 0;
}