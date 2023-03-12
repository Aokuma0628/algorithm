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
    char c = s[2*i];
    s[2*i] = s[2*i+1];
    s[2*i+1] = c;
  }

  cout << s << endl;

  return 0;
}