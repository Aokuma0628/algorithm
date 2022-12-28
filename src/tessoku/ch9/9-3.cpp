// A63 幅探索優先

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

const int32_t NUM_MAX = 100'000 + 9;

int main() {
  int32_t n = 0;
  int32_t m = 0;
  std::vector<int32_t> g[NUM_MAX];
  int32_t dist[NUM_MAX] = { 0 };
  std::queue<int32_t> q;

  cin >> n >> m;
  for (int32_t i = 1; i <= m; i++) {
    int32_t a = 0;
    int32_t b = 0;
    cin >> a >> b;

    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  for (int32_t i = 1; i <= n; i++) dist[i] = -1;
  q.push(1);
  dist[1] = 0;

  while(!q.empty()) {
    int32_t pos = q.front();
    q.pop();

    for (int32_t i = 0; i < (int32_t)g[pos].size(); i++) {
      int32_t next = g[pos][i];
      if (dist[next] == -1) {
        dist[next] = dist[pos] + 1;
        q.push(next);
      }
    }
  }

  for (int32_t i = 1; i <= n; i++) cout << dist[i] << endl;

  return 0;
}