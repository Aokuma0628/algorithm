#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  const uint32_t NUM_COUNT = 200'000 + 4;
}

int32_t main(void)
{
  uint32_t n,q = 0;
  uint32_t t[NUM_COUNT] = { 0 };
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t b[NUM_COUNT] = { 0 };
  std::map<int32_t, std::map<int32_t, bool>> ans;

  cin >> n >> q;
  for (uint32_t i = 0; i < q; i++) cin >> t[i] >> a[i] >> b[i];

  for (uint32_t i = 0; i < q; i++) {
    switch (t[i]) {
      case 1: {
        ans[a[i]][b[i]] = true;
        break;
      }
      case 2: {
        ans[a[i]][b[i]] = false;
        break;
      }
      case 3: {
        if (ans[a[i]][b[i]] && ans[b[i]][a[i]]) {
          cout << "Yes" << endl;
        }
        else {
          cout << "No" << endl;
        }
        break;
      }
      default:
        ;
    }
  }

  return 0;
}