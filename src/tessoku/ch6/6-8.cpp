// A43 問題を言い換える

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
  int32_t l = 0;
  int32_t a[NUM_MAX] = { 0 };
  char b[NUM_MAX] = { 0 };
  int32_t ans = 0;

  cin >> n >> l;
  for (int32_t i = 1; i <= n; i++) cin >> a[i] >> b[i];

  for (int32_t i = 1; i <= n; i++) {
    if (b[i] == 'E') ans = std::max(ans, l - a[i]);
    if (b[i] == 'W') ans = std::max(ans, a[i]);
  }
  cout << ans << endl;

  return 0;
}