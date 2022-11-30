// A27 最大公約数

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

uint64_t calc_greatest_common_divisor(
  uint64_t x,
  uint64_t y 
)
{
  // Euclidean Algorithm
  while (x != 0 && y != 0) {
    if (x >= y) {
      x = x % y;
    }
    else {
      y = y % x;
    }
  }
  return (x != 0) ? x : y;
}

int main() {
  int32_t a = 0;
  int32_t b = 0;
  uint64_t ans = 0;

  cin >> a >> b;

  ans = calc_greatest_common_divisor(a, b);

  cout << ans << endl;

  return 0;
}