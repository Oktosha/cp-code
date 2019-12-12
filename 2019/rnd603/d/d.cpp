#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, const vector<vector<bool>> &g, vector<bool> &visited) {
  visited[v] = true;
  for (int i = 0; i < 26; ++i) {
    if (g[v][i] && !visited[i]) {
      dfs(i, g, visited);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<bool> letter_is_in_passwords(26, false);
  vector<vector<bool>> g(26, vector<bool>(26, false));
  int N;
  cin >> N;
  for (int word = 0; word < N; ++word) {
    string s;
    cin >> s;
    for (auto ch : s) {
      letter_is_in_passwords[ch - 'a'] = true;
    }
    for (auto ch1 : s) {
      for (auto ch2 : s) {
        g[ch1 - 'a'][ch2 - 'a'] = true;
        g[ch2 - 'a'][ch1 - 'a'] = true;
      }
    }
  }

  int ans = 0;
  vector<bool> visited(26, false);
  for (int i = 0; i < 26; ++i) {
    if (letter_is_in_passwords[i] && !visited[i]) {
      ++ans;
      dfs(i, g, visited);
    }
  }
  cout << ans << "\n";
  return 0;
}