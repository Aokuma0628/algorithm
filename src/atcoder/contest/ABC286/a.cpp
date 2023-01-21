#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

const int32_t NUM_COUNT = 100 + 4;

int32_t main(void)
{
  int32_t n, p, q, r, s;
  int32_t a[NUM_COUNT] = { 0 };
  int32_t b[NUM_COUNT] = { 0 };
  int32_t pq[NUM_COUNT] = { 0 };
  int32_t rs[NUM_COUNT] = { 0 };
  int32_t cnt_pq = 0;
  int32_t cnt_rs = 0;

  cin >> n >> p >> q >> r >> s;

  for (int32_t i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    if (p <= i && i <= q) pq[cnt_pq++] = a[i];
    if (r <= i && i <= s) rs[cnt_rs++] = a[i];
  }

  cnt_pq = 0;
  cnt_rs = 0;
  for (int32_t i = 1; i <= n; i++) {
    if (p <= i && i <= q) b[i] = rs[cnt_rs++];
    if (r <= i && i <= s) b[i] = pq[cnt_pq++];
  }

  for (int32_t i = 1; i <= n; i++) {
    if (i >= 2) cout << " ";
    cout << b[i];
  }

  return 0;
}