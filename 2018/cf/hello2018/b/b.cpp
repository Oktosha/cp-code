#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	vector<bool> is_leaf(n + 1, false);
	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].push_back(i);
	}

	for (int i = 2; i <= n; ++i) {
		if (g[i].empty())
			is_leaf[i] = true;
	}

	bool is_pine = true;
	for (int i = 1; i <= n; ++i) {
		if (!is_leaf[i]) {
			int n_leafs = 0;
			for (int v : g[i]) {
				if (is_leaf[v])
					++n_leafs;
			}
			is_pine = is_pine && (n_leafs >= 3);
		}
	}

	cout << (is_pine ? "Yes" : "No") << endl;
	return 0;
}