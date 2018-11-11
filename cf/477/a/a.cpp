#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 10000000008;

long long get_trip_time(long long x0, long long x1, 
	                    long long t_h, long long t_v,
	                    const vector<long long> &pos) {
	if (pos.size() == 0) {
		return INF;
	}
	long long ans = INF;
	auto it = lower_bound(pos.begin(), pos.end(), x0);
	if (it != pos.end()) {
		long long xs = *it;
		if (xs < x1) {
			ans = min(ans, t_h + t_v);
		} else {
			ans = min(ans, t_h + t_v + 2LL * (xs - x1));
		}
	}
	if (it != pos.begin()) {
		--it;
		long long xs = *it;
		ans = min(ans, t_h + t_v + 2LL * (x0 - xs));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;
	vector<long long> stairs(cl);
	for (int i = 0; i < cl; ++i) {
		cin >> stairs[i];
	}
	vector<long long> elevator(ce);
	for (int i = 0; i < ce; ++i) {
		cin >> elevator[i];
	}
	long long q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		long long x0, y0, x1, y1;
		cin >> y0 >> x0 >> y1 >> x1;
		if (y0 == y1) {
			cout << abs(x0 - x1) << "\n";
		} else {
			long long t_h = abs(x0 - x1);
			long long t_stairs = abs(y1 - y0);
			long long t_elevator = (abs(y1 - y0) + v - 1LL) / v;
			if (x0 > x1) {
				swap(x0, x1);
			}
			long long ans = get_trip_time(x0, x1, t_h, t_stairs, stairs);
			ans = min(ans, get_trip_time(x0, x1, t_h, t_elevator, elevator));
			cout << ans << "\n";
		}
	}

	return 0;
}
