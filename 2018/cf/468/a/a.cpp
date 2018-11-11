#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000500;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		g[p].push_back(i); 
	}
	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : g[v]) {
			if (dist[u] == INF) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}

	vector<int> dist_cnt(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		++dist_cnt[dist[i]];
	}
	int ans = 0;
	for (int i = 0; i < dist_cnt.size(); ++i) {
		ans += dist_cnt[i] % 2;
	}
	cout << ans << endl;
	return 0;
}
