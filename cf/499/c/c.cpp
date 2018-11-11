#include <iostream>
#include <vector>

using namespace std;

bool can_fly(long double fuel, long double mass, const vector<long double> &a) {
	for (int i = 0; i < a.size(); ++i) {
		long double needed_fuel = (fuel + mass) / a[i];
		if (needed_fuel > fuel) {
			return false;
		}
		fuel -= needed_fuel;
	}
	return true;
}

const long double INF = 1e+9 + 5;

int main() {
	int n;
	cin >> n;
	long double mass;
	cin >> mass;
	vector<long double> a(2 * n);
	int pos = 2 * n - 1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		/*
		if (x == 1) {
			cout << -1 << endl;
			return 0;
		}
		*/
		a[i * 2] = x;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		/*
		if (x == 1) {
			cout << -1 << endl;
			return 0;
		}
		*/
		a[(2 * n + i * 2 - 1) % (2 * n)] = x;
	}

	/*
	for (int i = 0; i < 2 * n; ++i) {
		cerr << a[i] << " ";
	}
	cerr << endl;
	*/

	long double l = 0;
	long double r = INF + 5;
	for (int i = 0; i < 150; ++i) {
		long double m = (l + r) / 2.0;
		if (can_fly(m, mass, a)) {
			r = m;
		} else {
			l = m;
		}
	}

	if (r > INF) {
		cout << -1 << endl;
		return 0;
	}

	cout.precision(12);
	cout << fixed << r << endl;

	return 0;
}
