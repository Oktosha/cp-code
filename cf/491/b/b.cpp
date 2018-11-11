#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] *= 2;
		sum += a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (sum < 9 * n) {
			long long diff = 10 - a[i];
			sum += diff;
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}