// A37 足された回数を考える

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
  int64_t n = 0;
  int64_t m = 0;
  int64_t b = 0;
  int64_t a[NUM_MAX] = { 0 };
  int64_t c[NUM_MAX] = { 0 };

  cin >> n >> m >> b;

  for (int32_t i = 1; i <= n; i++) cin >> a[i];
  for (int32_t j = 1; j <= m; j++) cin >> c[j];

  int64_t ans = 0;
  for (int32_t i = 1; i <= n; i++) ans += a[i] * m;
  ans += b * n * m;
  for (int32_t j = 1; j <= m; j++) ans += c[j] * n;


  cout << ans << endl;

  return 0;
}