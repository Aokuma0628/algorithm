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
    MULTIPLE = 46,
  };


}

namespace {
  void main_logic(
    std::array<uint32_t, MULTIPLE> a,
    std::array<uint32_t, MULTIPLE> b,
    std::array<uint32_t, MULTIPLE> c
  )
  {
    uint64_t ans = 0;

    for (uint32_t i = 0; i < MULTIPLE; i++) {
      for (uint32_t j = 0; j < MULTIPLE; j++) {
        for (uint32_t k = 0; k < MULTIPLE; k++) {
          if ((i + j + k) % MULTIPLE == 0) {
              ans += (uint64_t)(a[i]) * b[j] * c[k];
          }
        }
      }
    }

    cout << ans << endl;

    return;
  }
}

int32_t main(void)
{
  uint32_t n = 0;
  std::array<uint32_t, MULTIPLE> a = { 0 };
  std::array<uint32_t, MULTIPLE> b = { 0 };
  std::array<uint32_t, MULTIPLE> c = { 0 };

  cin >> n;
  for (uint32_t i = 0; i < n; i++) {
    uint32_t val = 0;
    cin >> val;
    a[val % MULTIPLE] += 1;
  }

  for (uint32_t i = 0; i < n; i++) {
    uint32_t val = 0;
    cin >> val;
    b[val % MULTIPLE] += 1;
  }

  for (uint32_t i = 0; i < n; i++) {
    uint32_t val = 0;
    cin >> val;
    c[val % MULTIPLE] += 1;
  }

  main_logic(a, b, c);

  return 0;
}