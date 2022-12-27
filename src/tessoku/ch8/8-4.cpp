// A54 連想配列

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t q = 0;
  std::map<std::string, int32_t> score;

  cin >> q;
  for (int32_t i = 1; i <= q; i++) {
    int32_t type = 0;
    std::string s;
    int32_t x;

    cin >> type;
    
    switch (type) {
    case 1:
      cin >> s >> x;
      score[s] = x;
      break;
    case 2:
      cin >> s;
      cout << score[s] << endl;
      break;
    default:
      ;
    }
  }

  return 0;
}