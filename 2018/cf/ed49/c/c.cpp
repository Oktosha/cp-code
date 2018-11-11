#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 10005;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test = 0; test < T; ++test) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<int> b;
		for (int i = 1; i < a.size();) {
			if(a[i] == a[i - 1]) {
				b.push_back(a[i]);
				++i;
			}
			++i;
		}
		int ans_i = 1;
		for (int i = 2; i < b.size(); ++i) {
			if (b[i] * b[ans_i - 1] < b[ans_i] * b[i - 1]) {
				ans_i = i;
			}
		}

		cout << b[ans_i] << " " << b[ans_i] << " " << b[ans_i - 1] << " " << b[ans_i - 1] << "\n";
	}
	return 0;
}
