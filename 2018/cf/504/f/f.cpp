#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u;
	int v;
	long long w;
};

int l;
vector<int> tin, tout;
int timer;
vector <vector<int>> up;

void dfs (int v, int p, const vector<vector<int>> &g) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, v, g);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

void dfs1(int v, const vector<vector<int>> &g, vector<bool> &visited) {
	visited[v] = true;
	for (auto u : g[v]) {
		if (!visited[u]) {
			dfs1(u, g, visited);
		}
	}
}

bool is_connected(int n, const vector<Edge> &edge) {
	vector<vector<int>> g(n + 1);
	for (auto e : edge) {
		g[e.v].push_back(e.u);
		g[e.u].push_back(e.v);
	}
	vector<bool> visited(n + 1, false);
	dfs1(1, g, visited);
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void dfs_deep(int v, int p, const vector<vector<int>> &g, vector<bool> &visited, vector<long long> &deep) {
	visited[v] = true;
	deep[v] = deep[p] + 1;
	for (auto u : g[v]) {
		if (!visited[u]) {
			dfs_deep(u, v, g, visited, deep);
		}
	}
}

int main() {
	int n, k, m;
	cin >> n >> k >> m;


	vector<vector<int>> g(n + 1);
	for (int i = 0; i < k; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	tin.resize(n + 1),  tout.resize(n + 1),  up.resize(n + 1);
	l = 1;
	while ((1<<l) <= (n + 1))  ++l;
	for (int i=0; i<n; ++i)  up[i].resize (l+1);
	dfs (0, 0, g);

	vector<Edge> edge(m);
	for (int i = 0; i < m; ++i) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}

	if (!is_connected(n, edge)) {
		cout << -1 << endl;
		return 0;
	}

	vector<bool> visited(n + 1, false);
	vector<long long> deep(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs_deep(i, 0, g, visited, deep);
			g[0].push_back(i);
			g[i].push_back(0);
		}
	}

	reverse(edge.begin(), edge.end());
	vector<long long> sum(n + 1, 0);

	for (auto e : edge) {
		int f = lca(e.u, e.v);
		cerr << 
		sum[e.u] = sum[f] + e.w * (deep[e.u] - deep[f]);
		sum[e.v] = sum[f] + e.w * (deep[e.v] - deep[f]);
	}


	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += sum[i] - sum[up[i][0]];
	}

	cout << ans << endl;


	return 0;
}
