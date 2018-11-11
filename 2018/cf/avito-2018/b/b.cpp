#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	unordered_map<int, long long> max_x;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		long long x;
		cin >> a >> x;
		max_x[a] = max(max_x[a], x);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		long long x;
		cin >> a >> x;
		max_x[a] = max(max_x[a], x);
	}
	long long ans = 0;
	for (auto it = max_x.begin(); it != max_x.end(); ++it) {
		ans += it->second;
	}
	cout << ans << endl;
	return 0;
}