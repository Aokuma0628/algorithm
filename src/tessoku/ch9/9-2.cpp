// A62 深さ探索優先

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
  int32_t n = 0;
  int32_t m = 0;
  std::vector<int32_t> g[NUM_MAX];
  bool visited[NUM_MAX] = { 0 };

  cin >> n >> m;
  for (int32_t i = 1; i <= m; i++) {
    int32_t a = 0;
    int32_t b = 0;
    cin >> a >> b;

    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  //深さ優先探索
  std::stack<int32_t> next;
  next.push(1);
  
  while (next.size()) {
    int32_t pos = next.top();
    visited[pos] = true;
    next.pop();

    for (int32_t i = 0; i < (int32_t)g[pos].size(); i++) {
      int32_t side = g[pos][i];
      if (!visited[side]) next.push(side);
    }
  }

  std::string s = "The graph is connected.";
  for (int32_t i = 1; i <= n; i++) {
    if (!visited[i]) {
      s = "The graph is not connected.";
      break;
    }
  }

  cout << s << endl;

  return 0;
}