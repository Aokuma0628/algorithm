// A39 一手先を考える

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
  int32_t a[NUM_MAX] = { 0 };
  int32_t cnt[100] = { 0 };
  int64_t ans = 0;

  cin >> n;
  for (int32_t i = 1; i <= n; i++) cin >> a[i];
  for (int32_t i = 1; i <= n; i++) cnt[a[i]]++;

  for (int32_t i = 1; i <= 100; i++) {
    ans += (int64_t)cnt[i] * (int64_t)(cnt[i] - 1) * (int64_t)(cnt[i] - 2) / 6;
  }
  cout << ans << endl;

  return 0;
}