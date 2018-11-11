#include <bits/stdc++.h>

using namespace std;

const int INF = 100500;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int max_a = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		max_a = max(a[i], max_a);
	}

	int max_k = max_a + m;
	int l = 0;
	int r = INF;
	int total_people = m + accumulate(a.begin(), a.end(), 0);
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (*max_element(a.begin(), a.end()) > m || total_people > m * n) {
			l = m;
		} else {
			r = m;
		}
	}
	int min_k = r;
	cout << min_k << " " << max_k << endl;
	return 0;
}
