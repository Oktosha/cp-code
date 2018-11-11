#include <bits/stdc++.h>

using namespace std;

struct Voter {
	int p;
	long long c;
	bool operator < (Voter v) const {
		return c < v.c;
	}
};

const long long INF = 1'000'000'000ll * 3000ll;
int main() {
	int n, m;
	cin >> n >> m;
	vector<Voter> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].p >> a[i].c;
		--a[i].p;
	}
	sort(a.begin(), a.end());
	vector<vector<int>> b(m);
	for (int i = 0; i < a.size(); ++i) {
		b[a[i].p].push_back(i);
	}

	long long min_cost = INF;
	for (int cut = 0; cut < n; ++cut) {
		// cerr << "Cut = " << cut << endl;

		vector<bool> used(n, false);
		long long cur_cost = 0;
		long long n_voted = b[0].size();
		for (int i = 1; i < m; ++i) {
			if (b[i].size() > cut) {
				int needed = b[i].size() - cut;
				for (int j = 0; j < needed; ++j) {
					cur_cost += a[b[i][j]].c;
					used[b[i][j]] = true;
					++n_voted;
				}
			}
		}
		// cerr << "cost of cut " << cur_cost << endl;
		// cerr << "n voted from rivals: " << (n_voted - b[0].size()) << endl;
		// cerr << "voters left to buy:" << max(0ll, cut + 1 - n_voted) << endl;

		for (int i = 0; i < n && n_voted < (cut + 1); ++i) {
			if (!used[i] && (a[i].p != 0)) {
				cur_cost += a[i].c;
				++n_voted;
			}
		}

		// cerr << "total voted " << n_voted << endl;
		// cerr << "total cost " << cur_cost << endl;
		// cerr << endl;
		if (n_voted >= cut + 1) {
			min_cost = min(min_cost, cur_cost);
		}
	}

	cout << min_cost << endl;


	return 0;
}