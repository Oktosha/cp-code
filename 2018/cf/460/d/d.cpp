#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> topsorted;
vector<vector<int>> g;
vector<int> color;

bool are_cycles = false;

void dfs(int v) {
	// cerr << "dfs " << v << endl;
	if (are_cycles) {
		return;
	}

	if (color[v] == 2) {
		return;
	}
	if (color[v] == 1) {
		are_cycles = true;
		return;
	}

	color[v] = 1;
	for (int u : g[v]) {
		// cerr << "edge " << v << " " << u << endl;
		dfs(u);
	}
	color[v] = 2;
	// cerr << "put to tpsrt " << v << endl;
	topsorted.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
	}
	color.resize(n, 0);
	topsorted.reserve(n);
	for (int i = 0; i < n; ++i) {
		dfs(i);
		// cerr << "After dfs from " << i << endl;
		/*
		for (int j = 0; j < topsorted.size(); ++j) {
			cerr << topsorted[j] << " ";
		}
		cerr << endl;
		*/
		
		if (are_cycles) {
			cout << -1 << endl;
			return 0;
		}
	}
	vector<vector<int>> dp(n, vector<int>(26, 0));
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int u = topsorted[i];
		// cerr << u << " " << s[u] << endl;
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			for (int v : g[u]) {
				dp[u][ch - 'a'] = max(dp[v][ch - 'a'], dp[u][ch - 'a']);
			}
			ans = max(ans, dp[u][ch - 'a']);
		}
		++dp[u][s[u] - 'a'];
		ans = max(ans, dp[u][s[u] - 'a']);
	}

	cout << ans << endl;

	return 0;
}
