// A39 一手先を考える

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 300'000 + 9;

int main() {
  int32_t n = 0;
  int32_t l[NUM_MAX] = { 0 };
  int32_t r[NUM_MAX] = { 0 };
  std::vector<std::pair<int32_t, int32_t>> tmp;
  int32_t time = 0;
  int32_t ans = 0;

  cin >> n;
  for (int32_t i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    tmp.emplace_back(std::make_pair(r[i], l[i]));
  } 

  std::sort(tmp.begin(), tmp.end());
  for (int32_t i = 0; i < n; i++) {
    int32_t r_time = tmp[i].first;
    int32_t l_time = tmp[i].second;

    if (time <= l_time) {
      time = r_time;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}