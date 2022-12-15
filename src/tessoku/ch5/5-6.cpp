// A30 余りの計算 割り算

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main() {
  int64_t n = 0;
  int64_t ans = 0;

  cin >> n;

  ans = n / 3 + n / 5 - n / (3 * 5);

  cout << ans << endl;

  return 0;
}