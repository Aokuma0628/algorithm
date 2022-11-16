// A06

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;

int main() {
  uint32_t n, q = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t l[NUM_COUNT] = { 0 };
  uint32_t r[NUM_COUNT] = { 0 };
  uint32_t sum[NUM_COUNT] = { 0 };

  cin >> n >> q;

  for (uint32_t i = 1; i <= n; i++) cin >> a[i];
  for (uint32_t i = 1; i <= q; i++) cin >> l[i] >> r[i];

  sum[0] = 0;
  for (uint32_t i = 1; i <=n; i++) sum[i] = a[i] + sum[i - 1];

  for (uint32_t i = 1; i <=q; i++) {
    cout << sum[r[i]] - sum[l[i] - 1] << endl;
  }

  return 0;
}