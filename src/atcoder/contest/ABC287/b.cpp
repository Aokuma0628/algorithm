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
  const int32_t NUM_MAX = 1'000 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  int32_t m = 0;
  int32_t sn[NUM_MAX] = { 0 };
  int32_t tm[NUM_MAX] = { 0 };
  int32_t ans = 0;

  cin >> n >> m;

  for (int32_t i = 0; i < n; i++) {
    std::string s;
    cin >> s;
    sn[i] = stoi(s, NULL, 10) % 1000;
  }

  for (int32_t i = 0; i < m; i++) {
    std::string t;
    cin >> t;
    tm[i] = stoi(t, NULL, 10);
  }

  for (int32_t i = 0; i < n; i++) {
    for (int32_t j = 0; j < m; j++) {
      if (sn[i] == tm[j]) {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}