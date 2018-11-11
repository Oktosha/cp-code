#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(2 * n);
	vector<bool> is_ok(n, false);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (!is_ok[a[i]]) {
			auto next = find(a.begin() + i + 1, a.end(), a[i]);
			int n_swaps = next - (a.begin() + i + 1);
			ans += n_swaps;
			a.erase(next);
			a.insert(a.begin() + i, a[i]);
			is_ok[a[i]] = true;
			/*
			cerr << "moved " << a[i] << ", " << n_swaps << " swaps used" << endl;
			for (int j = 0; j < 2 * n; ++j) {
				cerr << a[j] << " ";
			}
			cerr << endl;
			*/
		}
	}
	cout << ans << endl;
	return 0;
}