// A11 配列の二分探索

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;

static int32_t search(
  uint32_t x,
  uint32_t n,
  uint32_t a[]
)
{
  uint32_t l = 1;
  uint32_t r = n;

  while (l <= r) {
    uint32_t m = (l + r) / 2;
    if (x < a[m]) {
      r = m - 1;
    }
    else if (x == a[m]) {
      return m;
    }
    else {
      l = m + 1;
    }
  }

  return -1;
}

int main() {
  uint32_t n,x = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  int32_t ans = 0;

  cin >> n >> x;
  for (uint32_t i = 1; i <= n; i++) cin >> a[i];
  ans = search(x, n, a);
  cout << ans << endl;

  return 0;
}