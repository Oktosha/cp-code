#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.size(); ++i) {
      if((i >= 2) && (s[i - 2] == 't') && (s[i - 1] == 'w') && (s[i] == 'o')
         && (i + 2 < s.size()) && (s[i] == 'o') && (s[i + 1] == 'n') && (s[i + 2] == 'e')) {
        ans.push_back(i + 1);
      } else if ((i >= 2) && (s[i - 2] == 't') && (s[i - 1] == 'w') && (s[i] == 'o')) {
        ans.push_back(i);
      } else if ((i + 2 < s.size()) && (s[i] == 'o') && (s[i + 1] == 'n') && (s[i + 2] == 'e')) {
        ans.push_back(i + 2);
      }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}