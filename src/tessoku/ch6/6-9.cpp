// A44 データの持ち方を工夫する

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 200'000 + 9;

int main() {
  int32_t n = 0;
  int32_t q = 0;
  int32_t a[NUM_MAX] = { 0 };
  bool rev = false;

  cin >> n >> q;

  for (int32_t i = 1; i <= n; i++) a[i] = i;

  for (int32_t i = 1; i <= q; i++) {
    int32_t type = 0;
    int32_t x = 0;
    int32_t y = 0;

    cin >> type;
    switch (type) {
    case 1:
      cin >> x >> y;
      if (!rev) a[x] = y;
      else a[n + 1 - x] = y;
      break;
    case 2:
      rev = !rev;
      break;
    case 3:
      cin >> x;
      if (!rev) cout << a[x] << endl;
      else cout << a[n + 1 - x] << endl;
      break;
    default:
      ;
    }
  }

  return 0;
}