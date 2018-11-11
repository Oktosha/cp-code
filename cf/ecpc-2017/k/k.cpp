#include <iostream>
using namespace std;

int main() {

	freopen("katryoshka.in", "r", stdin);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		long long n, m, k;
		cin >> n >> m >> k;
		cout << "Case " << test << ": ";
		if (m > n) {
			cout << min(k, n) << "\n";
			continue;
		}
		cout << min(k, m + ((n - m) / 2LL)) << "\n";
	}
	

	return 0;
}
