#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 200'000 + 4;
}


int32_t main(void)
{
  int32_t n = 0;
  int32_t m = 0;
  std::vector<int32_t> list_a[NUM_MAX];
  int32_t ans = 0;

  cin >> n >> m;

  for (int32_t i = 1; i <= m; i++) {
    int32_t c = 0;
    cin >> c;
    for (int32_t j = 1; j <= c; j++) {
      int32_t a = 0;
      cin >> a;
      list_a[i].emplace_back(a);
    }
  }

  int32_t flg = 1;

  while ((1 << m) > flg) {
    bool num_flg[NUM_MAX] = { 0 };
    for (int32_t i = 1; i <= m; i++) {
      if (flg & (1 << (i - 1))) {
        for (int32_t j = 0; j < (int32_t)list_a[i].size(); j++) {
          num_flg[list_a[i][j]] = true;
        }
      }
    }

    bool ans_flg = true;
    for (int32_t i = 1; i <= n; i++) {
      if (!num_flg[i]) ans_flg = false;
    }
    if (ans_flg) ans++;
    flg++;
  }

  cout << ans << endl;

  return 0;
}