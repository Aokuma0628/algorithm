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
  std::array<uint32_t, NUM_COUNT> a;
  int32_t fill_val = -1;
  std::map<uint32_t, uint64_t> inc;

  cin >> n;
  for (uint32_t i = 1; i <= n; i++) cin >> a[i];
  cin >> q;

  for (uint32_t j = 0; j < q; j++) {
    uint32_t key = 0;
    uint32_t x,i = 0;

    cin >> key;
    switch (key) {
    case 1:
      cin >> x;
      fill_val = x;
      inc.clear();
      break;
    case 2:
      cin >> i >> x;
      if (!inc.count(i)) {
        inc[i] = 0;
      }
      inc[i] += x;
      break;
    case 3: {
      uint64_t ans = 0;
      cin >> i;
      if (fill_val < 0) {
        ans += a[i];        
      }
      else {
        ans += fill_val;
      }
      if (inc.count(i)) {
        ans += inc[i];
      }

      cout << ans << endl;
      break;
    }
    default:
      ;
    }
  }

  return 0;
}