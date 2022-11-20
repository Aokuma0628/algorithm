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

  const uint32_t NUM_COUNT = 200 + 4;
}

int32_t main(void)
{
  uint32_t n,k = 0;
  uint32_t a[NUM_COUNT] = { 0 };

  cin >> n >> k;
  for (uint32_t i = 0; i < n; i++) cin >> a[i];

  for (uint32_t i = 0; i < n; i++) {
    if (i >= 1) cout << " ";
    cout << a[i + k];
  }

  return 0;
}