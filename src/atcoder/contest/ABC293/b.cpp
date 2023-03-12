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
  const int32_t NUM_MAX = 200'000 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  bool call[NUM_MAX] = { 0 };
  int32_t a[NUM_MAX] = { 0 };
  int32_t cnt = 0;

  cin >> n;
  cnt = n;

  for (int32_t i = 1; i <= n; i++) cin >> a[i];

  for (int32_t i = 1; i <= n; i++) {
    if (!call[i]) {
      if (!call[a[i]]) cnt--;
      call[a[i]] = true;
    }
  }

  cout << cnt << endl;
  int32_t tmp = 0;
  for (int32_t i = 1; i <= n; i++) {
    if (!call[i]) {
      if (tmp > 0) cout << " ";
      cout << i;
      tmp++;
    }
  }

  return 0;
}