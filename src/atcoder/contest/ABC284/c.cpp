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

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  const int32_t NUM_MAX = 100 + 4;
}

int32_t main(void)
{
  int32_t n = 0;
  int32_t m = 0;
  int32_t cnt = 0;
  std::vector<int32_t> point[NUM_MAX];
  bool visited[NUM_MAX] = { 0 };

  cin >> n >> m;

  for (int32_t i = 0; i < m; i++) {
    int32_t u = 0;
    int32_t v = 0;

    cin >> u >> v;
    point[u].emplace_back(v);
    point[v].emplace_back(u);
  }

  //深さ優先探索
  for (int32_t p = 1; p <= n; p++) {
    std::stack<int32_t> next;
    bool is_cnt = false;
    next.push(p);
  
    while (next.size()) {
      int32_t pos = next.top();
      next.pop();

      if (visited[pos] && next.size() == 0) {
        break;
      }
      is_cnt = true;
      visited[pos] = true;


      for (int32_t i = 0; i < (int32_t)point[pos].size(); i++) {
        int32_t side = point[pos][i];
        if (!visited[side]) {
          next.push(side);
        }
      }
    }

    if (is_cnt) cnt++;
  }

  cout << cnt << endl;

  return 0;
}