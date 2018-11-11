#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long INF = 1000000000000000009;

struct Cost {
	long long c;
	long long n;
	bool operator < (Cost other) const {
		return (1LL << other.n) * c < (1LL << n) * other.c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	long long n, l;
	cin >> n >> l;
	vector<Cost> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i].c;
		c[i].n = i;
	}
	sort(c.begin(), c.end());
	/*
	for (int i = 0; i < n; ++i) {
		cerr << c[i].n << " " << c[i].c << endl;
	}
	*/
	long long ans = INF;
	long long pref_cost = 0;
	for (int i = 0; (i < n) && (l > 0); ++i) {
		long long v = 1LL << c[i].n;
		long long k_lower = l / v;
		long long k_upper = k_lower + ((l % v > 0) ? 1 : 0);
		ans = min(ans, pref_cost + c[i].c * k_upper);
		l -= v * k_lower;
		pref_cost += c[i].c * k_lower;
		/*
		cerr << "bottle " << c[i].n << " " << c[i].c << endl;
		cerr << "k " << k_lower << " " << k_upper << endl;
		cerr << "ans " << ans << endl;
		cerr << "pref_cost " << pref_cost << endl;
		cerr << "l " << pref_cost << endl;
		cerr << endl;
		*/
	}
	cout << ans << endl;
	return 0;
}