// A53 優先度付きキュー

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t q = 0;
  std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> cost;

  cin >> q;
  for (int32_t i = 1; i <= q; i++) {
    int32_t type = 0;
    int32_t x;

    cin >> type;
    
    switch (type) {
    case 1:
      cin >> x;
      cost.push(x);
      break;
    case 2:
      cout << cost.top() << endl;
      break;
    case 3:
      cost.pop();
      break;
    default:
      ;
    }
  }

  return 0;
}