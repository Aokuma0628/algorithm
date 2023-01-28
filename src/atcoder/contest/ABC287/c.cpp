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
#include <queue>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 200'000 + 4;
}


int32_t main(void)
{
  int32_t n = 0;
  int32_t m = 0;
  std::vector<int32_t> list[NUM_MAX];
  bool flg[NUM_MAX] = { 0 };
  std::queue<int32_t> q;
  bool is_renketu = true;

  cin >> n >> m;

  for (int32_t i = 0; i < m; i++) {
    int32_t u = 0;
    int32_t v = 0;
    cin >> u >> v;

    list[u].emplace_back(v);
    list[v].emplace_back(u);
  }

  q.push(1);
  flg[1] = true;

  while (q.size()) {
    int32_t next = q.front();
    q.pop();

    for (int32_t i = 0; i < (int32_t)list[next].size(); i++) {
      int32_t tmp = list[next][i];
      if (!flg[tmp]) {
        q.push(tmp);
        flg[tmp] = true;
      }
    }
  }

  for (int32_t i = 1; i <= n; i++) {
    if (flg[i] == false) {
      is_renketu = false;
      break;
    }
  }

  if (is_renketu && n == (m + 1)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }


  return 0;
}