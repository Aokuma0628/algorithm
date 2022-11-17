// A10 チャレンジ問題

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;
const uint32_t MAX_PEOPLE = 100 + 4;

int main() {
  uint32_t n,d = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t l[NUM_COUNT] = { 0 };
  uint32_t r[NUM_COUNT] = { 0 };
  uint32_t max_l[NUM_COUNT] = { 0 };
  uint32_t max_r[NUM_COUNT] = { 0 };

  cin >> n;
  for (uint32_t i = 1; i <= n; i++) cin >> a[i];
  cin >> d;
  for (uint32_t i = 1; i <=d; i++) cin >> l[i] >> r[i];

  for (uint32_t i = 1; i <=n; i++) {
    max_l[i] = std::max(max_l[i - 1], a[i]);
  }
  for (uint32_t i = n; i >= 1; i--) {
    max_r[i] = std::max(max_r[i + 1], a[i]);
  }

  for (uint32_t i = 1; i <= d; i++) {
    uint32_t ans = std::max(max_l[l[i] - 1], max_r[r[i] + 1]);
    cout << ans << endl;
  }

  return 0;
}