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

namespace {
  enum {
    OK = 1,
    NG = 0,
    NUM_COUNT = 3,
  };

  const double PI = 3.141592653589793;
}

namespace {
  double calc_radian_to_degree(
    double radian
  )
  {
    return radian * 180.0 / PI;
  }

  void main_logic(
    int32_t t,
    int32_t l,
    int32_t x,
    int32_t y,
    std::vector<int> e
  )
  {
    int32_t i;

    for (i = 0; i < e.size(); i++) {
      double ey = -1.0 * l / 2.0 * sin(2.0 * PI * e[i] / t);
      double ez = l / 2.0 * (1.0 - cos(2.0 * PI * e[i] / t));

      double hor = sqrt(std::pow(x, 2.0) + std::pow((y - ey), 2.0));
      double vec = sqrt(pow(ez, 2.0));

      double radian = atan(vec / hor);
      double degree = calc_radian_to_degree(radian);
      if (degree > 90.0) degree -= 90.0;

      cout << std::fixed;
      cout << std::setprecision(7) << degree <<  endl;
    }

    return;
  }
}


int32_t main(void)
{
  int32_t t, l, x, y, q = 0;
  std::vector<int> e;
  int32_t i;

  std::cin >> t;
  std::cin >> l >> x >> y;
  std::cin >> q;

  for (i = 0; i < q; i++) {
    int32_t val;
    std::cin >> val;
    e.push_back(val);
  }

  main_logic(t, l, x, y, e);

  return 0;
}