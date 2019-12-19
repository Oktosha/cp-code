#include <iostream>
#include <vector>

using namespace std;

vector<int> count_sums(string s) {
  vector<int> ans(26, 0);
  for (auto ch : s) {
    ++ans[ch - 'a'];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string p, h;
    cin >> p >> h;
    vector<int> p_sums = count_sums(p);
    bool is_hash = false;
    for (int i = 0; i + p.size() <= h.size(); ++i) {
      auto h_sums = count_sums(h.substr(i, p.size()));
      is_hash = is_hash || (h_sums == p_sums);
    }
    cout << (is_hash ? "YES" : "NO") << "\n";
  }
  return 0;
}
