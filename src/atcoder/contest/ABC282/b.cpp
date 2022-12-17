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

  const int32_t MAX = 30 + 4;
  const char MARU = 'o';
  const char BATU = 'x';
}

int32_t main(void)
{
  int32_t n = 0;
  int32_t m = 0;
  char s[MAX][MAX] = {{ 0 }};
  int32_t ans = 0;

  cin >> n >> m;
  for (int32_t i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int32_t i = 0; i < n; i++) {
    for (int32_t j = i + 1; j < n; j++) {
      bool all_maru = true;
      for (int32_t k = 0; k < m; k++) {
        if (s[i][k] == MARU || s[j][k] == MARU) {
          //nothing
        }
        else {
          all_maru = false;
        }
      }

      if (all_maru) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}