// A30 余りの計算 割り算

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int32_t DIVISOR = 1'000'000'007;

int64_t calc_power_remain(
  int64_t a,
  int64_t b,
  int64_t m
)
{
  int64_t p = a;
  int64_t ans = 1;

  for (int32_t i = 0; i < 30; i++) {
    int32_t wari = (1 << i);

    if (b & wari) ans = (ans * p) % m;

    p = (p * p) % m;
  }

  return ans;
}

int main() {
  int32_t n = 0;
  int32_t r = 0;
  int64_t top = 1;
  int64_t bottom = 1;
  int64_t ans = 0;

  cin >> n >> r;

  for (int32_t i = 1; i <= n; i++) top = (top * i) % DIVISOR;

  for (int32_t i = 1; i <= r; i++) bottom = (bottom * i) % DIVISOR;
  for (int32_t i = 1; i <= (n - r); i++) bottom = (bottom * i) % DIVISOR;

  ans = (top * calc_power_remain(bottom, DIVISOR - 2, DIVISOR)) % DIVISOR;

  cout << ans << endl;

  return 0;
}