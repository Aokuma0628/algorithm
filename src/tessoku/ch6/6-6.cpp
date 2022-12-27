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

const int32_t NUM_MAX = 200'000 + 9;

int main() {
  int32_t n = 0;
  char s[NUM_MAX] = { 0 };
  bool ans = false;

  cin >> n;
  for (int32_t i = 1; i <= n; i++) cin >> s[i];

  for (int32_t i = 1; i <= n - 2; i++) {
    if (s[i] == 'R' && s[i+1] == 'R' && s[i+2] == 'R') {
      ans = true;
      break;
    }
    if (s[i] == 'B' && s[i+1] == 'B' && s[i+2] == 'B') {
      ans = true;
      break;
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}