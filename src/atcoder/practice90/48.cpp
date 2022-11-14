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
    MULTIPLE = 46,
  };
}

namespace {
  void main_logic(
    uint32_t k,
    vector<uint32_t> score
  )
  {
    uint64_t sum = 0;
    
    std::sort(score.begin(), score.end());
    std::reverse(score.begin(), score.end());

    for (uint32_t i = 0; i < k; i++) {
      sum += score[i];
    }

    cout << sum << endl;

    return;
  }
}

int32_t main(void)
{
  uint32_t n,k = 0;
  std::vector<uint32_t> score = { 0 };

  cin >> n >> k;

  for (uint32_t i = 0; i < n; i++) {
    uint32_t val_a = 0;
    uint32_t val_b = 0;

    cin >> val_a >> val_b;
    score.emplace_back(val_b);
    score.emplace_back(val_a - val_b);
  }

  main_logic(k, score);

  return 0;
}