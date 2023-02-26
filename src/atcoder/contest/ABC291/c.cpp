#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stack>
#include <queue>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 400'000 + 4;
  const int32_t OFFSET = 200'000;
}


int32_t main(void)
{
  std::map<int32_t, bool> xy[NUM_MAX];
  int32_t n = 0;
  std::string s;
  int32_t x = OFFSET;
  int32_t y = OFFSET;
  bool ans = false;

  cin >> n;
  cin >> s;

  xy[x][y] = true;
  for (int32_t i = 0; i < n; i++) {
    switch(s[i]) {
      case 'R':
        x += 1;
        break;
      case 'L':
        x -= 1;
        break;
      case 'U':
        y += 1;
        break;
      case 'D':
        y -= 1;
       break;
      default:
        ;
    }
    auto result = xy[x].find(y);

    if (result != xy[x].end()) {
      ans = true;
      break;
    }
    else {
      xy[x][y] = true;
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}