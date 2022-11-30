// A29 余りの計算 累乗

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int64_t calc_power_remain(
  int32_t a,
  int32_t b,
  int32_t m
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
  int32_t a = 0;
  int32_t b = 0;

  cin >> a >> b;

  cout << calc_power_remain(a, b, 1'000'000'007) << endl;

  return 0;
}