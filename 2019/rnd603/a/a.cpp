#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    vector<int> c(3);
    cin >> c[0] >> c[1] >> c[2];
    sort(c.begin(), c.end(), greater<>());
    int ans = 0;
    {
      int diff0 = c[1] - c[2];
      ans += diff0;
      c[0] -= diff0;
      c[1] -= diff0;
    }
    assert(c[1] == c[2]);
    assert(c[0] >= c[1]);

    int k = min(c[0] - (c[0] % 2), c[1] * 2);
    assert(k % 2 == 0);
    c[0] -= k;
    c[1] -= k / 2;
    c[2] -= k / 2;
    ans += k;

    assert(c[0] == 1 || c[0] == 0 || c[1] == 0);
    ans += c[1];

    cout << ans << "\n";
  }
  return 0;
}
