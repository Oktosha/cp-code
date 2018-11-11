#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long n, q;
	cin >> n >> q;
	for (int test = 0; test < q; ++test) {
		long long x, y;
		cin >> x >> y;
		x;
		y;
		long long ans = 0;
		long long n_in_odd = (n + 1) / 2;
		long long n_in_even = n / 2;
		if ((x + y) % 2 == 1) {
			ans += (n * n + 1ll) / 2ll;
			swap(n_in_even, n_in_odd);
		}
		long long prev_x = x - 1;
		if (prev_x >= 0) {
			ans += (prev_x + 1) / 2 * n_in_odd;
			ans += prev_x / 2 * n_in_even;
		}
		// cerr << "Last number in previous row: " << ans << endl;
		ans += (y + 1) / 2;

		cout << ans << endl;

	}
	return 0;
}
