// A26 素数判定

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const uint32_t NUMBER_COUNT = 10'000 + 4;

bool isPrime(
  int32_t x
)
{
  int32_t sqrt = (int32_t)std::sqrt(x);

  for (int32_t i = 2; i <= sqrt; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  int32_t q = 0;
  int32_t x[NUMBER_COUNT] = { 0 };

  cin >> q;
  for (int32_t i = 0; i < q; i++) cin >> x[i];

  for (int32_t i = 0; i < q; i++) {
    if (isPrime(x[i])) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}