#include <bits/stdc++.h>

using namespace std;

const long long INF = 1'308'983'066;
const long long MODULO = 1'000'000'007;
int main() {
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	map<long long, long long> a;
	a[INF] = 1;
	long long min_ac = 0;
	long long max_ac = INF;
	for (int q = 0; q < Q; ++q) {
		string cmd;
		long long x;
		cin >> cmd >> x;
		if (cmd == "ADD") {
			auto it = a.upper_bound(x);
			long long val = it->second;
			a.emplace(x, val);
		} else {
			if (x < min_ac || x > max_ac) {
				cout << 0 << endl;
				return 0;
			}
			auto it = a.find(x);
			long long val = it->second;

			if (it == a.begin())
				min_ac = 0;
			else {
				auto prev_it = it;
				--prev_it;
				min_ac = prev_it->first;
			}

			auto next_it = next(it);
			max_ac = next_it->first;
			next_it->second += val;
			next_it->second %= MODULO;
			a.erase(it);
		}
		cerr << "After " << cmd << " " << x << endl;
		for (auto it = a.begin(); it != a.end(); ++it) {
			cerr << it->first << " " << it->second << endl;
		}
		cerr << min_ac << " " <<max_ac << endl;
		cerr << endl;
	}
	long long ans = 0;
	for (auto it = a.lower_bound(min_ac); it != a.lower_bound(max_ac); ++it) {
		ans += it->second;
		ans %= MODULO;
	}
	ans += a.find(max_ac)->second;
	ans %= MODULO;
	cout << ans << endl;
	return 0;
}
