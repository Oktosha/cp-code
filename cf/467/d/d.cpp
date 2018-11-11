#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>> const &g, vector<int> &color, bool &is_cycle) {
	color[v] = 1;
	for (auto u : g[v]) {
		if (color[u] == 1) {
			is_cycle = true;
		} else if (color[u] == 0) {
			dfs(u, g, color, is_cycle);
		}
	}
	color[v] = 2;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<vector<int>> rg(n + 1);
	vector<vector<int>> next(n + 1, {-1, -1});
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		if (k == 0) {
			next[i][0] = 0;
			q.push(i);
		} else {
			g[i] = vector<int>(k);
			for (int j = 0; j < k; ++j) {
				cin >> g[i][j];
				rg[g[i][j]].push_back(i);
			}
		}
	}
	int s;
	cin >> s;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (next[v][0] != -1) {
			for (int u : rg[v]) {
				if (next[u][1] == -1) {
					next[u][1] = v;
					q.push(u); 
				}
			}
		}
		if (next[v][1] != -1) {
			for (int u : rg[v]) {
				if (next[u][0] == -1) {
					next[u][0] = v;
					q.push(u); 
				}
			}
		}
	}
	if (next[s][1] != -1) {
		cout << "Win" << endl;
		int v = s;
		bool i = 1;
		while (v != 0) {
			cout << v << " ";
			v = next[v][i];
			i = !i;
		}
		cout << endl;
	} else {
		vector<int> color(n + 1, 0);
		bool is_cycle = false;
		dfs(s, g, color, is_cycle);
		if (is_cycle) {
			cout << "Draw" << endl;
		} else {
			cout << "Lose" << endl;
		}
	}
	return 0;
}
