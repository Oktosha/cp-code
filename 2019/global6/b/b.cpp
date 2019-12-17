#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    long long x;
    cin >> x;
    if (x >= 15 && x % 14 > 0 && x % 14 <= 6) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}