#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vector<int> left_balance(n + 1);
    left_balance[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int jar;
      cin >> jar;
      if (jar == 1) {
        left_balance[i] = left_balance[i - 1] + 1;
      } else {
        left_balance[i] = left_balance[i - 1] - 1;
      }
    }
    vector<int> right(n);
    for (int i = 0; i < n; ++i) {
      cin >> right[i];
      if (right[i] == 2) {
        right[i] = -1;
      }
    }
    map<int, int> min_jars_for_balance;
    int balance = 0;
    min_jars_for_balance[0] = n;
    for (int i = n - 1; i >= 0; --i) {
      balance += right[i];
      min_jars_for_balance[balance] = i;
    }
    int ans = 2 * n;
    for (int i = 0; i <= n; ++i) {
      if (min_jars_for_balance.count(-left_balance[i]) > 0) {
        ans = min(ans, n - i + min_jars_for_balance[-left_balance[i]]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}