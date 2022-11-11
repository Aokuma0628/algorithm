#include <cstdint>

namespace {
  const double PI = 3.141592653589793;
}

uint64_t calc_greatest_common_divisor(
  uint64_t x,
  uint64_t y 
)
{
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

double calc_radian_to_degree(
  double radian
)
{
  return radian * 180.0 / PI;
}
