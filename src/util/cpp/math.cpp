#include <cstdint>

namespace {
  const double PI = 3.141592653589793;
}

 uint64_t calc_combination(
  uint32_t n,
  uint32_t k
 )
 {
  // return nCk
  double answer  = 1.0;

  if (k > n / 2) k = n - k;

  for (uint32_t i = 1; i <= k; i++) {
    double divided = (double)(n - i + 1);
    double divisor = (double)i;

    answer *= divided / divisor;
  }

  return (uint64_t)answer;
 }

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

uint64_t calc_least_common_multiple(
  uint64_t x,
  uint64_t y
)
{
  /* ２数x,y の最大公約数を G、最小公倍数を L とおくと下式が成り立つ。
      L = xy/G
  */
  uint64_t max_divisor = calc_greatest_common_divisor(x, y);

  if (x / max_divisor > UINT64_MAX / y) {
    return 0;
  }
  else {
    return x / max_divisor * y;
  }
}

double calc_radian_to_degree(
  double radian
)
{
  return radian * 180.0 / PI;
}
