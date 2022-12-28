// A64 ダイクストラ法

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
  std::vector<std::pair<int32_t, int32_t>> g[NUM_MAX];
  int32_t est[NUM_MAX] = { 0 };
  bool dem[NUM_MAX] = { 0 };
  std::priority_queue<std::pair<int32_t, int32_t>,
                      std::vector<std::pair<int32_t, int32_t>>,
                      std::greater<std::pair<int32_t, int32_t>>> q;

  cin >> n >> m;
  for (int32_t i = 1; i <= m; i++) {
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    cin >> a >> b >> c;

    g[a].emplace_back(std::make_pair(b, c));
    g[b].emplace_back(std::make_pair(a, c));
  }

  for (int32_t i = 1; i <= n; i++) est[i] = INT32_MAX;

  est[1] = 0;
  q.push(std::make_pair(est[1], 1));

  while (!q.empty()) {
    int32_t pos = q.top().second;
    q.pop();

    if (dem[pos]) continue;

    dem[pos] = true;
    for (int32_t i = 0; i < (int32_t)g[pos].size(); i++) {
      int32_t next = g[pos][i].first;
      int32_t dist = g[pos][i].second;
      if (est[next] > est[pos] + dist) {
        est[next] = est[pos] + dist;
        q.push(std::make_pair(est[next], next));
      }
    }
  }

  for (int32_t i = 1; i <= n; i++) {
    if (est[i] == INT32_MAX) cout << "-1" << endl;
    else cout << est[i] << endl;
  }

  return 0;
}