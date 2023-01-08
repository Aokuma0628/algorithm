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

const int32_t NUM_COUNT = 12;

int32_t main(void)
{
  std::string s[NUM_COUNT];
  int32_t n = 0;

  cin >> n;

  for (int32_t i = 0; i < n; i++) {
    cin >> s[i];
  }
  

  for (int32_t i = n - 1; i >= 0; i--) {
    cout << s[i] << endl;
  }

  return 0;
}