#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 100500;
vector<int> bfs(int start, const vector<vector<int>> &g) {
	// cerr << "bfs from " << start << endl;
	vector<int> dist(g.size(), INF);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	
	while (!q.empty()) {
		int v = q.front();
		// cerr << v << endl;
		q.pop();
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	return dist;
}


int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	--s;
	--t;
	// cerr << "s" << s << " t" << t << endl;
	vector<vector<int>> g(n);
	vector<vector<bool>> g_matrix(n, vector<bool>(n, false));

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
		g_matrix[a][b] = true;
		g_matrix[b][a] = true;
	}
	// cerr << "data read" << endl;
	
	vector<int> ds = bfs(s, g);
	vector<int> dt = bfs(t, g);

	/*
	cerr << "ds" << endl;
	for (int i = 0; i < n; ++i) {
		cerr << ds[i] << " ";
	}
	cerr << endl;

	cerr << "dt" << endl;
	for (int i = 0; i < n; ++i) {
		cerr << dt[i] << " ";
	}
	cerr << endl;
	*/

	int dist = ds[t];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!g_matrix[i][j] 
				&& (ds[i] + dt[j] + 1 >= dist) 
				&& (ds[j] + dt[i] + 1 >= dist)) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
