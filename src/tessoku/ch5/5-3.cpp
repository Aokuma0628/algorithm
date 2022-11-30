// A28 余りの計算

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUMBER_COUNT = 100'000 + 4;
const uint32_t DIVISOR = 10'000;


int main() {
  int32_t n = 0;
  char t[NUMBER_COUNT] = { 0 };
  int32_t a[NUMBER_COUNT] = { 0 };
  int64_t ans = 0;

  cin >> n;
  for (int32_t i = 0; i < n; i++) cin >> t[i] >> a[i];

  for (int32_t i = 0; i < n; i++) {
    if (t[i] == '+') ans += a[i];
    if (t[i] == '-') ans -= a[i];
    if (t[i] == '*') ans *= a[i];

    if (ans < 0) ans += DIVISOR;

    ans %= DIVISOR;
    cout << ans << endl;
  }

  return 0;
}