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
  int32_t k = 0;

  cin >> k;

  for (char i = 0; i < k; i++) {
    char s = 'A' + i;

    cout << s;
  }

  return 0;
}