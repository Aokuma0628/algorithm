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


int32_t main(void)
{
  std::string s;
  int32_t i = 0;

  cin >> s;

  for (i = 0; i < s.size(); i++) {
    if (s[i] < 0x61) break;
  }

  cout << (i + 1) << endl;

  return 0;
}