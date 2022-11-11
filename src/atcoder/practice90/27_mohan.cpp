#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;

int main() {
  int N;
  std::string S[1 << 18];
  std::map<std::string, int> Map;

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> S[i];
    
    if (Map[S[i]] == 0) {
      Map[S[i]] = 1;
      cout << i << endl;
    }
  }
  return 0;
}