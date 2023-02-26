#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 1'000 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  std::vector<int32_t> arr_x;
  int32_t sum = 0;

  cin >> n;

  for (int32_t i = 0; i < 5 * n; i++) {
    int32_t x = 0;
    cin >> x;
    arr_x.emplace_back(x);
  }

  std::sort(arr_x.begin(), arr_x.end());

  for (int32_t i = n; i < 4 * n; i++) {
    sum += arr_x[i];
  }

  cout << (double)sum / (double)(3 * n) << endl;

  return 0;
}