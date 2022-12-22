// A38 上限値を考える

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 10'000 + 9;

int main() {
  int32_t d = 0;
  int32_t n = 0;
  int32_t l[NUM_MAX] = { 0 };
  int32_t r[NUM_MAX] = { 0 };
  int32_t h[NUM_MAX] = { 0 };
  int32_t lim[NUM_MAX] = { 0 };
  int32_t ans = 0; 

  cin >> d >> n;
  for (int32_t i = 1; i <= n; i++) cin >> l[i] >> r[i] >> h[i];

  for (int32_t i = 1; i <= d; i++) lim[i] = 24;

  for (int32_t i = 1; i <= n; i++) {
    for (int32_t j = l[i]; j <= r[i]; j++) lim[j] = std::min(lim[j], h[i]);
  }

  for (int32_t i = 1; i <= d; i++) ans += lim[i];
  cout << ans << endl;

  return 0;
}