// A08 二次元の累積和

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;
const uint32_t SIDE_SIZE = 1'500 + 4;

int main() {
  uint32_t h,w,q = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t b[NUM_COUNT] = { 0 };
  uint32_t c[NUM_COUNT] = { 0 };
  uint32_t d[NUM_COUNT] = { 0 };
  uint32_t x[SIDE_SIZE][SIDE_SIZE] = {{ 0 }};
  uint32_t sum[SIDE_SIZE][SIDE_SIZE] = {{ 0 }};

  cin >> h >> w;

  for (uint32_t i = 1; i <= h; i++) {
    for (uint32_t j = 1; j <= w; j++) {
      cin >> x[i][j];
    }
  }

  cin >> q;

  for (uint32_t i = 1; i <= q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  //横方向の累積和
  for (uint32_t i = 1; i <= h; i++) {
    for (uint32_t j = 1; j <= w; j++) {
      sum[i][j] = sum[i - 1][j] + x[i][j];
    }
  }

  // 縦方向の累積和
  for (uint32_t i = 1; i <= h; i++) {
    for (uint32_t j = 1; j <= w; j++) {
      sum[i][j] = sum[i][j - 1] + sum[i][j];
    }
  }

  for (uint32_t i = 1; i <= q; i++) {
    uint32_t ans =  sum[a[i] - 1][b[i] - 1] +
                    sum[c[i]][d[i]] -
                    sum[a[i] - 1][d[i]] -
                    sum[c[i]][b[i] - 1];

    cout << ans << endl;
  }

  return 0;
}