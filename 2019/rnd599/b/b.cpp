#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct DSU {
  int v;
  int cnt;
  int edge_cnt;
};

const int INF = 1005000;

int get_root(int v, vector<DSU> &dsu) {
  if (dsu[v].v == v) {
    assert(dsu[v].cnt > 0);
    return v;
  }
  assert(dsu[v].cnt == -INF);
  dsu[v].v = get_root(dsu[v].v, dsu);

  return dsu[v].v;
}

void join(int u, int v, vector<DSU> &dsu) {
  int new_root = get_root(u, dsu);
  int other = get_root(v, dsu);
  if (new_root == other) {
    return;
  }
  dsu[new_root].cnt += dsu[other].cnt;
  dsu[other].cnt = -INF;
  dsu[other].v = new_root;
}

int get_size(int v, vector<DSU> &dsu) {
  int root = get_root(v, dsu);
  return dsu[root].cnt;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);

  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    if (u < v) {
      swap(u, v);
    }
    g[u].push_back(v);
  }

  vector<DSU> dsu(n);
  for (int i = 0; i < n; ++i) {
    dsu[i] = {i, 1};
  }

  vector<int> roots = {0};

  for (int v = 1; v < n; ++v) {
    for (int u : g[v]) {
      int root = get_root(u, dsu);
      dsu[root].edge_cnt++;
    }
    for (int u : roots) {
      if (dsu[u].cnt > dsu[u].edge_cnt) {
        join(v, u, dsu);
      }
      dsu[u].edge_cnt = 0;
    }
    roots.push_back(v);
    auto it = remove_if(roots.begin(), roots.end(), [&dsu](int u){return dsu[u].v != u;});
    roots.erase(it, roots.end());
  }

  cout << roots.size() - 1 << endl;

  return 0;
}
