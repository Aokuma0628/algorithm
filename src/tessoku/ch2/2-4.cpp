// A09 二次元の累積和

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;
const uint32_t SIDE_SIZE = 1'500 + 4;

int main() {
  uint32_t h,w,n = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t b[NUM_COUNT] = { 0 };
  uint32_t c[NUM_COUNT] = { 0 };
  uint32_t d[NUM_COUNT] = { 0 };
  uint32_t diff[SIDE_SIZE][SIDE_SIZE] = {{ 0 }};
  uint32_t ans[SIDE_SIZE][SIDE_SIZE] = {{ 0 }};

  cin >> h >> w >> n;
  for (uint32_t i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  for (uint32_t i = 1; i <= n; i++) {
    diff[a[i]][b[i]] += 1;
    diff[a[i]][d[i] + 1] -= 1;
    diff[c[i] + 1][b[i]] -= 1;
    diff[c[i] + 1][d[i] + 1] += 1;
  }

  // 横累積和
  for (uint32_t i = 1; i <= h; i++) {
    for (uint32_t j = 1; j <= w; j++) {
      ans[i][j] = ans[i][j - 1] + diff[i][j];
    }
  }

  // 縦累積和
  for (uint32_t i = 1; i <= h; i++) {
    for (uint32_t j = 1; j <= w; j++) {
      ans[i][j] = ans[i - 1][j] + ans[i][j];
    }
  }

  for (uint32_t i = 1; i <= h; i++) {
    for (uint32_t j = 1; j <= w; j++) {
      if (j >= 2) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}