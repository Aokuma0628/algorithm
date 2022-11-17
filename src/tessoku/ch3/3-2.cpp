// A12 答えで二分探索

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;
const uint32_t MAX_NUMBER = 1'000'000'000;

static bool check(
  uint32_t mid,
  uint32_t n,
  uint32_t a[],
  uint32_t k
)
{
  uint64_t sum = 0;
  
  for (uint32_t i = 1; i <= n; i++) sum += mid / a[i];

  if (sum >= k) return true;
  
  return false;
}

int main() {
  uint32_t n,k,l,r = 0;
  uint32_t a[NUM_COUNT] = { 0 };

  cin >> n >> k;
  for (uint32_t i = 1; i <= n; i++) cin >> a[i];

  l = 1;
  r = MAX_NUMBER;

  while (l < r) {
    uint32_t mid = (l + r) / 2;
    bool ret = check(mid, n, a, k);
    if (ret) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }

  cout << l << endl;

  return 0;
}