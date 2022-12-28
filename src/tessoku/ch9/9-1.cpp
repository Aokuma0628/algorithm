// A61 グラフの実装方法

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

  cin >> n >> m;
  for (int32_t i = 1; i <= m; i++) {
    int32_t a = 0;
    int32_t b = 0;
    cin >> a >> b;

    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  for (int32_t i = 1; i <= n; i++) {
    cout << i << ": {";
    for (int32_t j = 0; j < g[i].size(); j++) {
      if (j >= 1) cout << ", ";
      cout << g[i][j];
    }
    cout << "}" << endl;
  }

  return 0;
}