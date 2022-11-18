// A13 しゃくとり法

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;

int main() {
  uint32_t n,k = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t max_idx[NUM_COUNT] = { 0 };
  uint64_t ans = 0;

  cin >> n >> k;
  for (uint32_t i = 1; i <= n; i++) cin >> a[i];

  for (uint32_t i = 1; i <= n - 1; i++) {
    if (i == 1)  { 
      max_idx[i] = 1;
    }
    else {
      max_idx[i] = max_idx[i - 1];
    }

    while (max_idx[i] < n && a[max_idx[i] + 1] - a[i] <= k) {
      max_idx[i] += 1;
    }
  }

  for (uint32_t i = 1; i <= n - 1; i++) {
    ans += max_idx[i] - i;
  }

  cout << ans << endl;

  return 0;
}