#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long w = 1;
	for (int i = 1; i < n; ++i) {
		w = max(w, abs(a[i] - a[i - 1]));
	}

	for (int i = 1; i < n; ++i) {
		if (!((abs(a[i] - a[i - 1]) == w) || (abs(a[i] - a[i - 1]) == 1))){
			cout << "NO" << endl;
			return 0;
		}
		if (abs(a[i] - a[i - 1]) == 1) {
			long long big = max(a[i], a[i - 1]);
			long long small = min(a[i], a[i - 1]);
			if (big % w == 1) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	cout << "1000000000 " << w << endl;
	return 0;
}
