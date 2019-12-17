#include <iostream>
#include <vector>

using namespace std;

struct Balance {
  long long b;
  int i;
  bool operator < (Balance other) const {
    return b < other.b;
  }
};

struct Edge {
  int u;
  int v;
  long long b;
};

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<Balance> balance(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    balance[i].i = i;
  }
  for (int i = 0; i < m; ++i) {
    long long u, v, s;
    cin >> u >> v >> s;
    balance[u].b -= s;
    balance[v].b += s;
  }
  /*
  cerr << "Balance" << "\n";
  for (int i = 0; i < n + 1; ++i) {
    cerr << balance[i].i << " " << balance[i].b << "\n";
  }
  cerr << "\n";
  */

  vector<Balance> negatives;
  vector<Balance> positives;
  for (int i = 0; i < n + 1; ++i) {
    if (balance[i].b < 0) {
      negatives.push_back({-balance[i].b, i});
    }
    if (balance[i].b > 0) {
      positives.push_back({balance[i].b, i});
    }
  }

  /*
  cerr << "Negatives" << "\n";
  for (int i = 0; i < negatives.size(); ++i) {
    cerr << negatives[i].i << " " << negatives[i].b << "\n";
  }
  cerr << "\n";

  cerr << "Positives" << "\n";
  for (int i = 0; i < positives.size(); ++i) {
    cerr << positives[i].i << " " << positives[i].b << "\n";
  }
  cerr << "\n";
  */

  vector<Edge> ans;
  int p = 0;
  for (int i = 0; i < negatives.size(); ++i) {
    while(negatives[i].b > 0) {
      long long b = min(negatives[i].b, positives[p].b);
      ans.push_back({negatives[i].i, positives[p].i, b});
      negatives[i].b -= b;
      positives[p].b -= b;
      if (positives[p].b == 0) {
        ++p;
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto e : ans) {
    cout << e.u << " " << e.v << " " << e.b << "\n";
  }

  return 0;
}
