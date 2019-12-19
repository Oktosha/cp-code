#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    long long a, b;
    cin >> a >> b;
    long long delta = abs(a - b);
    if (delta == 0) {
      cout << 0 << "\n";
      continue;
    }
    long long l = 0;
    long long r = 1'000'000;
    while(r - l > 1) {
      long long m = (r + l) / 2ll;
      if (m * (m + 1) / 2ll >= delta) {
        r = m;
      } else {
        l = m;
      }
    }
    while((r * (r + 1) / 2ll) % 2ll != delta % 2ll) {
      ++r;
    }
    cout << r << "\n";
  }
  return 0;
}
