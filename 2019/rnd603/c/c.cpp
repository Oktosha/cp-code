#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    long long x;
    cin >> x;
    vector<long long> ans;
    for (int p = 1; p <= sqrt(x) + 1; ++p) {
      ans.push_back(x / p);
      if ((x / p) > 0) {
        ans.push_back(x / (x / p));
      }
    }
    ans.push_back(0);
    sort(ans.begin(), ans.end());
    auto it = unique(ans.begin(), ans.end());
    ans.erase(it, ans.end());
    cout << ans.size()<< "\n";
    for (auto p : ans) {
      cout << p << " ";
    }
    cout << endl;
  }
  return 0;
}
