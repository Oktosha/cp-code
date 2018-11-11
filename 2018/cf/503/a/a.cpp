#include <bits/stdc++.h>

using namespace std;

long long solve(long long t1, long long f1, long long t2, long long f2, long long a, long long b) {
	if (t1 == t2) {
		return abs(f1 - f2);
	}
	long long ans = abs(t1 - t2);
	if (f1 < a && f2 < a) {
		ans += (a - f1) + (a - f2);
	} else if (f1 > b && f2 > b) {
		ans += (f1 - b) + (f2 - b);
	} else {
		ans += abs(f1 - f2);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; ++i) {
		long long t1, f1, t2, f2;
		cin >> t1 >> f1 >> t2 >> f2;
		cout << solve(t1, f1, t2, f2, a, b) << "\n";
	}
	return 0;
}
