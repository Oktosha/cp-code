#include <bits/stdc++.h>

using namespace std;


void dfs_color(int v, const vector<vector<int>> &g,vector<int> &color, int cur_color) {
	color[v] = cur_color;
	for (auto u : g[v]) {
		if (color[u] == -1) {
			dfs_color(u, g, color, cur_color);
		}
	}
}


void dfs_cycle(int v, const vector<int> &next, vector<int> &stack, vector<int> &visited, vector<bool> &is_on_cycle) {
	visited[v] = 1;
	stack.push_back(v);

	if (visited[next[v]] == 1) {
		for (int i = stack.size() - 1; stack[i] != next[v]; --i) {
			is_on_cycle[stack[i]] = true;
		}
		is_on_cycle[next[v]] = true;
	}

	if (visited[next[v]] == 0) {
		dfs_cycle(next[v], next, stack, visited, is_on_cycle);
	}
	
	visited[v] = 2;
	stack.pop_back();

}
const long long INF = 100500;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> cost(n + 1);
	vector<int> next(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> next[i];
		g[i].push_back(next[i]);
		g[next[i]].push_back(i);
	}
	
	vector<int> color(n + 1, -1);
	int cur_color = 0;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1) {
			dfs_color(i, g, color, cur_color);
			++cur_color;
		}
	}

	/*
	cerr << "Colors" << endl;
	for (int i = 0; i <= n; ++i) {
		cerr << color[i] << " ";
	}
	cerr << endl;
	*/

	vector<bool> is_on_cycle(n + 1, false);
	vector<int> stack;
	vector<int> visited(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) {
			dfs_cycle(i, next, stack, visited, is_on_cycle);
		}
	}

	vector<long long> cmp_ans(cur_color, INF);
	for (int i = 1; i <= n; ++i) {
		if (is_on_cycle[i]) {
			cmp_ans[color[i]] = min(cmp_ans[color[i]], (long long) cost[i]);
		}
	}

	cout << accumulate(cmp_ans.begin(), cmp_ans.end(), 0) << endl;
	return 0;
}
