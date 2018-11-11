#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	long long total_gcd = 0;
	for (int i = 0; i < N; ++i) {
		long long x, y;
		cin >> x >> y;
		if (total_gcd == 0) {
			total_gcd = x * y;
		} else {
			total_gcd = gcd(total_gcd, x * y);
		}
	}

	if (total_gcd == 1) {
		cout << -1 << endl;
		return 0;
	}

	for (long long i = 2; i * i <= total_gcd; ++i) {
		if (total_gcd % i == 0) {
			cout << i << endl;
			return 0;
		}
	}

	cout << total_gcd << endl;
	return 0;
}
