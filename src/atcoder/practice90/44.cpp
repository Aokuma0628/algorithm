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
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };
}

namespace {
  

  void main_logic(
    uint32_t q,
    vector<uint32_t> a,
    vector<vector<uint32_t>> txy
  )
  {
    uint32_t shift_cnt = 0;
    for (uint32_t i = 0; i < q; i++) {
      switch (txy[i][0]) {
        case 1: {
          int32_t x = txy[i][1];
          int32_t y = txy[i][2];

          if (shift_cnt > 0) {
            x = x - shift_cnt % a.size();
            y = y - shift_cnt % a.size();

            if (x <= 0) x += a.size();
            if (y <= 0) y += a.size();
          }

          std::swap(a.at(x - 1), a.at(y - 1));
          break;
        }  
        case 2:
            shift_cnt++;
            // std::rotate(a.begin(), a.end() - 1, a.end());
          break;
        case 3: {
          int32_t idx = txy[i][1] - 1;
          if (shift_cnt > 0) {
            idx -= shift_cnt % a.size();
            if (idx < 0) idx += a.size();
          }
          cout << a.at(idx) << endl;
          break;
        }
        default:
          ;  // nothing
      }
    }

    return;
  }
}

int32_t main(void)
{
  uint32_t n,q = 0;
  vector<uint32_t> a;
  vector<vector<uint32_t>> txy;

  cin >> n >> q;

  for (uint32_t i = 0; i < n; i++) {
    uint32_t val = 0;
    cin >> val;
    a.emplace_back(val);
  }

  for (uint32_t i = 0; i < q; i++) {
    uint32_t t,x,y = 0;
    txy.emplace_back();
    cin >> t >> x >> y;
    txy[i].emplace_back(t);
    txy[i].emplace_back(x);
    txy[i].emplace_back(y);
  }

  main_logic(q, a, txy);

  return 0;
}