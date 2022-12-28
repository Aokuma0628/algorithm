// A60 チャレンジ問題

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 200'000 + 9;

int main() {
  int32_t n = 0;
  int32_t a[NUM_MAX] = { 0 };
  int32_t ans[NUM_MAX] = { 0 };
  std::stack<std::pair<int32_t, int32_t>> stock;

  cin >> n;
  for (int32_t i = 1; i <= n; i++) cin >> a[i];

  for (int32_t i = 1; i <= n; i++) {
    if (i >= 2) {
      stock.push(std::make_pair(i - 1, a[i - 1]));
      while (!stock.empty()) {
        int32_t price = stock.top().second;
        if (price <= a[i]) stock.pop();
        else break;
      }
    }

    if (!stock.empty()) ans[i] = stock.top().first;
    else ans[i] = -1;
  }

  for (int32_t i = 1; i <= n; i++) {
    if (i >= 2) cout << " ";
    cout << ans[i];
  }

  return 0;
}