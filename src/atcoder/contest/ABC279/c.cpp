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
  enum {
    OK = 1,
    NG = 0,
  };
}

vector<std::string> input(
  uint32_t h,
  uint32_t w
)
{
  vector<std::string> s(h);
  vector<std::string> x(w, std::string(h, '0'));

  for (uint32_t i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (uint32_t i = 0; i < h; i++) {
    for (uint32_t j = 0; j < w; j++) {
      x[j][i] = s[i][j];
    }
  }

  std::sort(x.begin(), x.end());
  return x;
}

int32_t main(void)
{
  uint32_t h = 0;
  uint32_t w = 0;

  cin >> h >> w;

  auto s = input(h, w);
  auto t = input(h, w);

  if (s == t) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}