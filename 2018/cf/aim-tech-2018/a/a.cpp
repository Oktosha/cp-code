#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	int ans_x, ans_y;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int sum = 0;
		int cnt_b = 0;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'B') {
				++cnt_b;
				sum += j;
			}
		}
		if (cnt_b != 0) {
			ans_y = sum / cnt_b;
		}
	}

	for (int i = 0; i < m; ++i) {
		int sum = 0;
		int cnt_b = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j][i] == 'B') {
				++cnt_b;
				sum += j;
			}
		}
		if (cnt_b != 0) {
			ans_x = sum / cnt_b;
		}
	}

	cout << (ans_x + 1) << " " << (ans_y + 1) << endl;

	return 0;
}
