#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long max_dist, n;
	cin >> max_dist >> n;

	cout << 1 << endl;
	fflush(stdout);

	int ans;
	cin >> ans;

	if (ans == 0) {
		return 0;
	}

	vector<bool> p(n);
	p[0] = (ans == 1);
	for (int i = 1; i < n; ++i) {
		cout << 1 << endl;
		fflush(stdout);
		cin >> ans;
		p[i] = (ans == 1);
	}

	long long l = 1;
	long long r = max_dist;
	int pos = 0;
	while (r - l > 1) {
		long long m = (r + l) / 2ll;
		cout << m << endl;
		fflush(stdout);
		cin >> ans;
		if (ans == 0) {
			return 0;
		}
		bool predicate = (ans == 1);
		if (!p[pos]) {
			predicate = !predicate;
		}
		pos = (pos + 1) % n;

		if (predicate) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << r << endl;


	return 0;
}
