// A66 Union-Find 木

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

class UnionFind {
  private:
    int32_t par[NUM_MAX];
    int32_t size[NUM_MAX];

    int32_t root(int32_t x) {
      int32_t pos = x;
      while (true) {
        if (par[pos] == -1) break;
        pos = par[pos];
      }

      return pos;
    }

  public:
    void init(int32_t n) {
      for (int32_t i = 1; i <= n; i++) {
        par[i] = -1;
        size[i] = 1;
      }
      return ;
    }

    void unite(int32_t u, int32_t v) {
      int32_t root_u = root(u);
      int32_t root_v = root(v);

      if (root_u == root_v) return;
      if (size[root_u] < size[root_v]) {
        par[root_u] = root_v;
        size[root_v] += size[root_u];
      }
      else {
        par[root_v] = root_u;
        size[root_u] += size[root_v];
      }

      return ;
    }

    bool same(int32_t u, int32_t v) {
      if (root(u) == root(v)) return true;
      else return false;
    }
};


int main() {
  int32_t n = 0;
  int32_t q = 0;
  UnionFind UF;

  cin >> n >> q;

  UF.init(n);
  for (int32_t i = 1; i <= q; i++) {
    int32_t x = 0;
    int32_t u = 0;
    int32_t v = 0;

    cin >> x >> u >> v;
    if (x == 1) {
      UF.unite(u, v);
    }
    else if (x == 2) {
      if (UF.same(u, v)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }

  return 0;
}