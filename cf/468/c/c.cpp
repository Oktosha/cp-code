#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
	int x;
	int d; // 1 seg starts, -1 seg ends;
	Event(int x, int d): x(x), d(d) {}
	bool operator < (Event e) const {
		return x < e.x || (x == e.x && d > e.d);
	}
};

const int MAX_N = 1005000;

vector<int> ndlen(vector<int> const &a) {
	vector<int> ans(a.size(), 1);
	vector<int> d(a.size() + 1, MAX_N);
	d[0] = -MAX_N;
	for (int i = 0; i < a.size(); ++i) {
		int j = int (upper_bound(d.begin(), d.end(), a[i]) - d.begin());
		d[j] = a[i];
		ans[i] = j;
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<Event> e;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		e.emplace_back(l, 1);
		e.emplace_back(r, -1);
	}
	e.emplace_back(1, 1);
	e.emplace_back(m, -1);
	sort(e.begin(), e.end());
	
	vector<int> b(m + 1, 0);
	int balance = 0;
	int x = 0;
	int i = 0;
	while (x <= m && i < e.size()) {
		if (e[i].x > x) {
			b[x] = balance;
			++x;
			continue;
		}
		while (i < e.size() && e[i].x == x && e[i].d == 1) {
			++i;
			++balance;
		}
		b[x] = balance;
		while(i < e.size() && e[i].x == x && e[i].d == -1) {
			++i;
			--balance;
		}
		++x;
	}
	
	/*
	cerr << "Balance for points" << endl;
	for (int i = 0; i <= m; ++i) {
		cerr << b[i] << " ";
	}
	cerr << endl << endl;
	*/

	b.erase(b.begin());
	auto pref = ndlen(b);
	reverse(b.begin(), b.end());
	auto suf = ndlen(b);
	reverse(suf.begin(), suf.end());

	/*
	cerr << "pref and suff max non-decreasing subsequence len" << endl;
	cerr << "x";
	for (int i = 0; i < b.size(); ++i) {
		cerr << " " << pref[i];
	}
	cerr << endl;
	cerr << "x";
	for (int i = 0; i < b.size(); ++i) {
		cerr << " " << suf[i];
	}
	cerr << endl;
	*/
	
	int ans = 0;
	for (int i = 0; i < b.size(); ++i) {
		ans = max(ans, pref[i] + suf[i] - 1);
	}
	cout << ans << endl;
	return 0;
}