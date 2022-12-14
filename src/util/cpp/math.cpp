#include <cstdint>
#include <cmath>

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

bool isPrime(
  int32_t x
)
{
  int32_t sqrt = (int32_t)std::sqrt(x);

  for (int32_t i = 2; i <= sqrt; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

// aのb乗した数値をmで割った時の余りを計算する
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