#include <iostream>
#include <set>
#include <utility>

int main() {
  using namespace std;

  unsigned N, Q;
  cin >> N >> Q;

  set<pair<unsigned, unsigned>> follows;

  for (unsigned _{}; _ < Q; ++_) {
    unsigned type, A, B;
    cin >> type >> A >> B;
    if (type == 1)
      follows.emplace(A, B);
    else if (type == 2)
      follows.erase({A, B});
    else
      cout << (follows.count({A, B}) && follows.count({B, A}) ? "Yes" : "No") << endl;
  }

  return 0;
}
