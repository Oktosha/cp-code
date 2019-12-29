#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N_TESTS;
  cin >> N_TESTS;
  for (int test = 0; test < N_TESTS; ++test) {
    long long n, p, k;
    cin >> n >> p >> k;
    vector<long long> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    long long remainder = 0;
    int ans = 0;
    for (int n_remaining = 0; n_remaining < k; ++n_remaining) {
      long long cost = remainder;
      if (cost > p) {
        continue;
      }
      int pos = n_remaining + k - 1;
      int cur_ans = n_remaining;
      while(cost <= p && pos < n) {
        cost += a[pos];
        pos += k;
        cur_ans += k;
      }
      if (cost > p) {
        cur_ans -= k;
      }

      ans = max(ans, cur_ans);

      remainder += a[n_remaining];
    }
    cout << ans <<  "\n";
  }
  return 0;
}
