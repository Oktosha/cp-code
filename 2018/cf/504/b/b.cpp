#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n, k;
	cin >> n >> k;

	long long l = max(1ll, k - n);
	long long r = min(k - 1ll, n);
	long long ans = max(0ll, r - l + 1ll);
	if (((k / 2ll) <= n) && (k % 2ll == 0ll)) {
		--ans;
	}

	cout << (ans / 2ll) << endl;

	return 0;
}
