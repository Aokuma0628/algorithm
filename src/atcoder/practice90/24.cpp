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
  };
}

namespace {
  void main_logic(
    uint32_t n,
    uint32_t k,
    std::vector<uint32_t> a,
    std::vector<uint32_t> b
  )
  {
    uint32_t i;
    uint64_t diff = 0;
    for (i = 0; i < n; i++) {
      diff += abs(a.at(i) - b.at(i));
      
      if (k < diff) {
        cout << "No" << endl;
        return;
      }
    }

    if ((diff - k) % 2 == 0) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }

    return;
  }
}


int32_t main(void)
{
  uint32_t n,k = 0;
  uint32_t i;
  std::vector<uint32_t> a,b;

  std::cin >> n >> k;

  for (i = 0; i < n; i++) {
    uint32_t val = 0;
    std::cin >> val;
    a.push_back(val);
  }

  for (i = 0; i < n; i++) {
    uint32_t val = 0;
    std::cin >> val;
    b.push_back(val);
  }

  main_logic(n, k, a, b);

  return 0;
}