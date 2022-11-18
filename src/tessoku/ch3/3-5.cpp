// A15 チャレンジ問題

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

int main() {
  uint32_t n = 0;
  std::vector<uint32_t> a;
  std::vector<uint32_t> sort_a;
  std::vector<uint32_t> ans;

  cin >> n;
  for (uint32_t i = 0; i < n; i++) {
    uint32_t val = 0;
    cin >> val;
    a.emplace_back(val);
    sort_a.emplace_back(val);
  }

  std::sort(sort_a.begin(), sort_a.end());
  sort_a.erase(std::unique(sort_a.begin(), sort_a.end()), sort_a.end());

  for (uint32_t i = 0; i < n; i++) {
    long int idx = std::lower_bound(sort_a.begin(), sort_a.end(), a[i]) - sort_a.begin();
    ans.emplace_back(idx + 1);
  }

  for (uint32_t i = 0; i < n; i++) {
    if (i >= 1) cout << " ";
    cout << ans.at(i);
  }

  return 0;
}