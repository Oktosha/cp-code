#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> ans;
	unordered_set<int> stack;
	vector<bool> used(n + 1, false);
	bool is_ans = false;
	try {
		dfs(1, 0, g, ans, stack);
	} catch (...) {
		is_ans = true;
	}
	if (is_ans) {
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}