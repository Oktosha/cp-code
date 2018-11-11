#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool ans = true;
	int prev = 1'000'000'500;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (max(x, y) <= prev) {
			prev = max(x, y);
			continue;
		}
		if (min(x, y) <= prev) {
			prev = min(x, y);
			continue;
		}
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}
