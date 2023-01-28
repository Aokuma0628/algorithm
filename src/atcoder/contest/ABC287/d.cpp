#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stack>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int32_t main(void)
{
  std::string s;
  std::string t;

  cin >> s;
  cin >> t;

  for (int32_t x = 0; x <= t.size(); x++) {
    std::string tmp_s;
    if (x < t.size()) {
      tmp_s = s.substr(0, x) + s.substr(s.size() - t.size() + x, t.size() - x);
    }
    else {
      tmp_s = s.substr(0, x);
    }

    bool not_match = false;
    for (int32_t j = 0; j < t.size(); j++) {
      if (t[j] == '?' || tmp_s[j] == '?') continue;

      if (t[j] != tmp_s[j]) {
        not_match = true;
        break;
      }
    }

    if (not_match) cout << "No" << endl;
    else cout << "Yes" << endl;
  }

  return 0;
}