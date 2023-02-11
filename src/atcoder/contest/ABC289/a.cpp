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
  int32_t n = 0;
  int32_t cnt = 0;

  cin >> n;

  for (int32_t i = 0; i < n; i++) {
    std::string s;
    cin >> s;
    
    if (s == "For") cnt++;
  }

  if (cnt > (n / 2)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}