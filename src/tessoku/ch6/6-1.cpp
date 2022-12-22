// A36 偶奇を考える

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main() {
  int32_t n = 0;
  int32_t k = 0;

  cin >> n >> k;

  if (k >= 2*n-2 && k%2 == 0) cout << "Yes" << endl;
  else cout << "No" << endl; 

  return 0;
}