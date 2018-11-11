#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long a, b, p, x;
	cin >> a >> b >> p >> x;
	vector<long long> a_power(p);
	a_power[0] = 1;
	for (int i = 1; i < p; ++i) {
		a_power[i] = (a_power[i - 1] * a) % p;
	}
	vector<long long> k_for_power(p - 1);
	vector<long long> n_for_diff(p, 0);
	for (long long i = 0; i < p - 1; ++i) {
		k_for_power[i] = (b * a_power[p - 1 - i]) % p;
		long long diff = (p + k_for_power[i] - i) % p;
		++n_for_diff[diff];
		if ((k_for_power[i] * a_power[i]) % p != b)
			cerr << "ERROR! ERROR!" << endl;
		// cerr << k_for_power[i] << " * "<< a << "^" << i << " = " << b << endl;
	}
	/*
	for (int i = 0; i < p; ++i) {
		cerr << "n for diff " << i << " is " << n_for_diff[i] << endl;
	}
	*/


	long long ans = 0;

	for (long long y = x - (x % (p - 1)); y <= x; ++y) {
		if (y % p == k_for_power[y % (p - 1)])
			++ans;
	}
	x = x - (x % (p - 1));

	for (long long diff = 0; diff < p; ++diff) {
		ans += n_for_diff[diff] * (x / (p * (p - 1)));
	}
	x = x % (p * (p - 1));


    long long n_diffs = x / (p - 1);
    for (long long diff = p, i = 0; i < n_diffs; ++i, --diff) {
    	ans += n_for_diff[diff % p];
    }

    cout << ans << endl;

	return 0;
}
