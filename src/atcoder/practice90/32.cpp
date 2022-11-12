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

namespace {
  enum {
    OK = 1,
    NG = 0,
    NUM_COUNT = 10,
  };
}

namespace {
  void main_logic(
    uint32_t n,
    std::array<std::array<uint32_t, NUM_COUNT>, NUM_COUNT> a,
    std::array<std::array<bool, NUM_COUNT>, NUM_COUNT> xy
  )
  {
    std::vector<uint32_t> people;
    uint32_t ans = UINT32_MAX;

    for (uint32_t i = 0; i < n; i++) {
      people.push_back(i);
    }

    do {
      uint32_t sum = 0;
      bool is_bad = false;

      for (uint32_t i = 0; i < n; i++) {
        if (i != (n - 1) && xy[people.at(i)][people.at(i + 1)] == true) {
          is_bad = true;
          break;
        }

        sum += a[people.at(i)][i];
      }

      if (is_bad) continue;
      ans = std::min(ans, sum);
    } while (std::next_permutation(people.begin(), people.end()));

    if (ans == UINT32_MAX) {
      cout << -1 << endl;
    }
    else {
      cout << ans << endl;
    }
  }

}

int32_t main(void)
{
  uint32_t n,m = 0;
  std::array<std::array<uint32_t, NUM_COUNT>, NUM_COUNT> a = {{ 0 }};
  std::array<std::array<bool, NUM_COUNT>, NUM_COUNT> xy = {{ false }};

  std::cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    for (uint32_t j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }

  std::cin >> m;

  for (uint32_t i = 0; i < m; i++) {
    uint32_t x, y = 0;
    std::cin >> x >> y;
    xy[x - 1][y - 1] = true;
    xy[y - 1][x - 1] = true;
  }

  main_logic(n, a, xy);

  return 0;
}