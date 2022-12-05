#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };
}

// 下記はACにはならないコード

vector<std::pair<int64_t, int64_t>> prime_factorize(int64_t num) {
  vector<std::pair<int64_t, int64_t> > res;

  for (int64_t a = 2; a * a <= num; ++a) {
    if (num % a != 0) continue;
    int64_t ex = 0;

    while (num % a == 0) {
        ex++;
        num /= a;
    }

    res.push_back({a, ex});
  }

  if (num != 1) res.push_back({num, 1});
  return res;
}

int32_t main(void)
{
  int64_t k = 0;
  size_t ans_idx = 0;

  cin >> k;
  auto prime = prime_factorize(k);

  ans_idx = prime.size() - 1;
  if (prime[ans_idx].second == 1) {
    cout << prime[ans_idx].first << endl;
  }
  else {
    int64_t ex = prime[ans_idx].second - 1;
    int64_t factor = prime[ans_idx].first;
    int64_t ans = factor;

    while (ex > 0) {
      ans++;
      auto p = prime_factorize(ans);
      for (int32_t i = 0; i < (int32_t)p.size(); i++) {
        if (p[i].first == factor) {
          ex -= p[i].second;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}