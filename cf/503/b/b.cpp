#include <bits/stdc++.h>

using namespace std;

int dfs(int v, const vector<int> &p, vector<bool> &visited) {
	if (visited[v]) {
		return v;
	}
	visited[v] = true;
	return dfs(p[v], p, visited);
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> p(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		vector<bool> visited(n + 1, false);
		cout << dfs(i, p, visited) << " ";
	}
	cout << endl;
	return 0;
}

