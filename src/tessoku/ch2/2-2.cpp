// A07 一次元の累積和

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;

int main() {
  uint32_t d,n = 0;
  uint32_t l[NUM_COUNT] = { 0 };
  uint32_t r[NUM_COUNT] = { 0 };
  uint32_t pre[NUM_COUNT] = { 0 };
  uint32_t ans[NUM_COUNT] = { 0 };

  cin >> d;
  cin >> n;

  for (uint32_t i = 1; i <= n; i++) cin >> l[i] >> r[i];

  for (uint32_t i = 1; i <= n; i++) {
    pre[l[i]] += 1;
    pre[r[i] + 1] -= 1;
  }

  ans[0] = 0;
  for (uint32_t i = 1; i <= d; i++) {
    ans[i] = pre[i] + ans[i - 1];
  }

  for (uint32_t i = 1; i <= d; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}