// A17 動的計画法の復元

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUM_COUNT = 100'000 + 4;

int main() {
  uint32_t n = 0;
  uint32_t place = 0;
  uint32_t a[NUM_COUNT] = { 0 };
  uint32_t b[NUM_COUNT] = { 0 };
  uint32_t dp[NUM_COUNT] = { 0 };
  std::vector<uint32_t> ans;
  

  cin >> n;
  for (uint32_t i = 2; i <= n; i++) cin >> a[i];
  for (uint32_t i = 3; i <= n; i++) cin >> b[i];

  dp[1] = 0;
  dp[2] = a[2];

  for (uint32_t i = 3; i <= n; i++) {
    dp[i] = std::min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
  }

  place = n;
  while (place >= 1) {
    ans.emplace_back(place);

    if (dp[place - 1] + a[place] == dp[place]) {
      place -= 1;
    }
    else {
      place -= 2;
    }
  }

  std::reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (uint32_t i = 0; i < ans.size(); i++) {
    if (i >= 1) cout << " ";
    cout << ans[i];
  }

  return 0;
}