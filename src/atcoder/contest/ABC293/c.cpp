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
#include <set>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  const int32_t NUM_MAX = 10 + 4;
}


static void dfs(int32_t i, int32_t j, int32_t *ans, int32_t h, int32_t w, std::set<int32_t>visited, int32_t a[NUM_MAX][NUM_MAX])
{

  if (i > h || j > w) return;
  if (visited.count(a[i][j])) return;

  if (i == h && j == w) {
    *ans += 1;
    return;
  }

  visited.insert(a[i][j]);
  dfs(i + 1, j, ans, h, w, visited, a);
  dfs(i, j + 1, ans, h, w, visited, a);
  visited.erase(a[i][j]);
  
  return;
}

int32_t main(void)
{
  int32_t h = 0;
  int32_t w = 0;
  int32_t a[NUM_MAX][NUM_MAX] = {{ 0 }};
  int32_t ans = 0;
  std::set<int32_t> visited;

  cin >> h >> w;

  for (int32_t i = 1; i <= h; i++) {
    for (int32_t j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  dfs(1, 1, &ans, h, w, visited, a);

  cout << ans << endl;

  return 0;
}