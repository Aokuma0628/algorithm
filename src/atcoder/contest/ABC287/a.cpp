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

  cin >> s;

  for (int32_t i = 0; i < s.length(); i++) {
    if (s[i] == '0') cout << '1';
    else cout << '0';
  }

  return 0;
}