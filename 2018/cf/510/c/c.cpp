#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int> taken(n, 0);
	int sp_pos = -1;
	int cnt_negative = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 0) {
			taken[i] = 1;
		}
		if (a[i] < 0) {
			++cnt_negative;
			if (sp_pos == -1 || a[i] > a[sp_pos]) {
				sp_pos = i;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) {
			taken[i] = 1;
			if (i == sp_pos && cnt_negative % 2 == 1) {
				taken[i] = 0;
			}
		}
	}

	int total_taken = accumulate(taken.begin(), taken.end(), 0);
	if (total_taken == n || total_taken == 0) {
		for (int i = 2; i <= n; ++i) {
			cout << 1 << " " << i << " " << 1 << "\n";
		}
		return 0;
	}

	int good_pos = find(taken.begin(), taken.end(), 1) - taken.begin();
	int bad_pos = find(taken.begin(), taken.end(), 0) - taken.begin();

	for (int i = 0; i < n; ++i) {
		if (i != good_pos && i != bad_pos) {
			cout << 1 << " " << (i + 1) << " " 
			     << ((taken[i] ? good_pos : bad_pos) + 1) << "\n";
		}
	}

	cout << 2 << " " << (bad_pos + 1) << "\n";

	return 0;
}