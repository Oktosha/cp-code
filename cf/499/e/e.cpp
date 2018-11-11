#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] %= k;
	}
	sort(a.begin(), a.end());
	if (a.back() == 0) {
		cout << 1 << "\n";
		cout << 0 << "\n";
		return 0;
	}

	long long total_gcd = a.back();
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != 0) {
			total_gcd = gcd(total_gcd, a[i]);
		}
	}
	vector<bool> ans(k);
	for (long long i = 0; i <= k; ++i) {
		ans[(i * total_gcd) % k] = true;
	}

	int ans_count = 0;
	for (int i = 0; i < k; ++i) {
		if (ans[i]) {
			++ans_count;
		}
	}
	cout << ans_count << endl;
	for (int i = 0; i < k; ++i) {
		if (ans[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}
