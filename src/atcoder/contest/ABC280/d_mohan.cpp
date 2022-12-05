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

// 公式解答
// int32_t main(void)
// {
//   int64_t k = 0;
//   int64_t ans = 0;

//   cin >> k;
//   for (int64_t i = 2; i * i <= k; i++) {
//     int64_t cnt = 0;
//     int64_t n = 0;

//     while (k % i == 0) {
//       k /= i;
//       cnt++;
//     }

//     while (cnt > 0) {
//       n += i;
//       int64_t x = n;
//       while (x % i == 0) {
//         x /= i;
//         cnt--;
//       }
//     }
//     ans = std::max(ans, n);
//   }
//   ans = std::max(ans, k);
//   cout << ans << endl;

//   return 0;
// }

// 下記サイトの解答(けんちょんさんの解答)
// https://drken1215.hatenablog.com/entry/2022/12/05/160400
using pll = std::pair<long long, long long>;  // (素因数, 指数)
vector<pll> prime_factorize(long long n) {
    vector<pll> res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        long long e = 0;
        while (n % p == 0) { n /= p, ++e; }
        res.emplace_back(p, e);
    }
    if (n != 1) res.emplace_back(n, 1);
    return res;
}

// n が p で何回割れるかを求める
long long how_many(long long n, long long p) {
    long long res = 0;
    while (n % p == 0) {
        n /= p;
        ++res;
    }
    return res;
}

int main() {
    // 入力
    long long K;
    cin >> K;

    // K を素因数分解する
    vector<pll> pf = prime_factorize(K);

    // 各素因数ごとに求めていく
    long long res = 0;
    for (auto [p, e] : pf) {
        long long f = 0;  // n! を素因数分解したときの p の指数
        for (long long n = p; ; ++n) {
            f += how_many(n, p);
            if (f >= e) {
                res = std::max(res, n);
                break;
            }
        }
    }
    cout << res << endl;
}