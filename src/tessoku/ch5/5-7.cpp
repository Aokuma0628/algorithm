// A30 余りの計算 割り算

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t n = 0;
  int32_t a = 0;
  int32_t b = 0;
  bool dp[NUM_MAX] = { 0 };

  cin >> n >> a >> b;

  for (int32_t i = 0; i <= n; i++) {
    if (i >= a && dp[i - a] == false) {
      dp[i] = true;
    }
    else if (i >= b && dp[i - b] == false) {
      dp[i] = true;
    }
    else {
      dp[i] = false;
    }
  }

  if (dp[n]) {
    cout << "First" << endl;
  }
  else {
    cout << "Second" << endl;
  }

  return 0;
}