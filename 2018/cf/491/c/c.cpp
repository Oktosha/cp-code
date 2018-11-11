#include <iostream>

using namespace std;

long long vasya_eats(long long s, long long k) {
	if (k == 0) {
		return 0;
	}
	long long ans = 0;
	int i = 0;
	while(s > 0) {
		// cerr << "day " << i << " ";
		// cerr << "s = " << s << endl;
		++i;
		ans += min(s, k);
		s -= min(k, s);
		s -= (s / 10LL);
	}
	return ans;
}
int main() {
	long long n;
	cin >> n;
	long long l = 0;
	long long r = n;
	while (r - l > 1) {
		long long m = (r + l) / 2LL;
		if (vasya_eats(n, m) < ((n + 1LL) / 2LL)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << r << endl;
	return 0;
}