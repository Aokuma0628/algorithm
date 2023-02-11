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
#include <stack>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 100 + 4;
}


int32_t main(void)
{
  int32_t n = 0;
  int32_t m = 0;
  std::vector<int32_t> list[NUM_MAX];
  int32_t ans[NUM_MAX] = { 0 };
  int32_t idx = 0;
  bool flg[NUM_MAX] = { 0 };
  std::stack<int32_t> stack;

  cin >> n >> m;

  for (int32_t i = 0; i < m; i++) {
    int32_t a = 0;
    cin >> a;

    list[a].emplace_back(a+1);
    list[a+1].emplace_back(a);
  }

  stack.push(1);
  flg[1] = true;

  while (stack.top() <= n) {
    bool can_next = false;
    int32_t next = stack.top();

    for (int32_t i = 0; i < (int32_t)list[next].size(); i++) {
      int32_t tmp = list[next][i];
      if (!flg[tmp]) {
        stack.push(tmp);
        flg[tmp] = true;
        can_next = true;
      }
    }

    if (!can_next) {
      int32_t next_num = stack.top() + 1;
      while(stack.size()) {
        int32_t num = stack.top();
        stack.pop();
        ans[idx] = num;
        idx++;
      }
      stack.push(next_num);
      flg[next_num] = true;
    }
  }

  for (int32_t i = 0; i < n; i++) {
    if (i >= 1) cout << " ";
    cout << ans[i];
  }


  return 0;
}