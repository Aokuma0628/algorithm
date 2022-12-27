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

const int32_t NUM_MAX = 300 + 9;

int main() {
  int32_t n = 0;
  int32_t k = 0;
  int32_t a[NUM_MAX] = { 0 };
  int32_t b[NUM_MAX] = { 0 };
  int32_t ans = 0;

  cin >> n >> k;
  for (int32_t i = 1; i <= n; i++) cin >> a[i] >> b[i];

  for (int32_t i = 1; i <= 100; i++) {
    for (int32_t j = 1; j <= 100; j++) {
      int32_t cnt = 0;

      for (int32_t l = 1; l <= n; l++) {
        if (a[l] >= i && a[l] <= i+k && b[l] >= j && b[l] <= j+k) cnt++;
      }

      ans = std::max(cnt, ans);
    }
  }

  cout << ans << endl;

  return 0;
}