#include <bits/stdc++.h>

using namespace std;

const int INF = 1'300'500;

int get_mask(string s) {
	int ans = 0;
	if (s.find('A') != string::npos) {
		ans += 1;
	}
	if (s.find('B') != string::npos) {
		ans += 2;
	}
	if (s.find('C') != string::npos) {
		ans += 4;
	}
	return ans;
}

int main() {
	vector<int> ans(8, INF);
	ans[0] = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int cost;
		cin >> cost;
		string vitamins;
		cin >> vitamins;
		int mask = get_mask(vitamins);
		ans[mask] = min(ans[mask], cost); 
	}

	for (int iter = 0; iter < 10; ++iter) {
		for (int mask = 0; mask < 8; ++mask) {
			for (int submask_it_1 = 0; submask_it_1 < 8; ++submask_it_1) {
				for (int submask_it_2 = 0; submask_it_2 < 8; ++submask_it_2) {
					int submask_1 = mask & submask_it_1;
					int submask_2 = mask & submask_it_2;
					if (((submask_1 | submask_2) & mask) == mask) {
						ans[mask] = min(ans[mask], ans[submask_1] + ans[submask_2]);
					}
				}
			}
		}
	}

	if (ans[7] >= INF) {
		cout << -1 << endl;
	} else {
		cout << ans[7] << endl;
	}

	return 0;
}