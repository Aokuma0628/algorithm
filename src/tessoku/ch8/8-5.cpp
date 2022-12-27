// A55 Set

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t q = 0;
  std::set<int32_t> card;

  cin >> q;
  for (int32_t i = 1; i <= q; i++) {
    int32_t type = 0;
    int32_t x = 0;

    cin >> type;
    
    switch (type) {
    case 1:
      cin >> x;
      card.insert(x);
      break;
    case 2:
      cin >> x;
      card.erase(x);
      break;
    case 3: {
      cin >> x;
      auto itr = card.lower_bound(x);
      if (itr == card.end()) cout << "-1" << endl;
      else cout << (*itr) << endl;
      break;
    }
    default:
      ;
    }
  }

  return 0;
}