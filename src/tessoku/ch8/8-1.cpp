// A51 スタック

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t q = 0;
  //int32_t type[NUM_MAX] = { 0 };
  std::stack<std::string> book;

  cin >> q;
  for (int32_t i = 1; i <= q; i++) {
    int32_t type = 0;
    std::string s;

    cin >> type;
    
    switch (type) {
    case 1:
      cin >> s;
      book.push(s);
      break;
    case 2:
      cout << book.top() << endl;
      break;
    case 3:
      book.pop();
      break;
    default:
      ;
    }
  }

  return 0;
}