#include <bits/stdc++.h>

using namespace std;

int ask(int i) {
	cout << "? " << (i + 1) << endl;
	fflush(stdout);	
	int x;
	cin >> x;
	return x;
}

void ans(int i) {
	cout << "! " << (i + 1) << endl;
	fflush(stdout);
}

int sign(int x) {
	if (x == 0) {
		return 0;
	}
	if (x < 0) {
		return -1;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	if ((n / 2) % 2) {
		ans(-2);
		return 0;
	}
	long long a = ask(0);
	long long b = ask(n / 2);
	if (a == b) {
		ans(0);
		return 0;
	}

	int l = 0;
	int r = n / 2;
	while (r - l > 1) {
		// cerr << "l " << l << " r " << r << endl;
		int m = (l + r) / 2;
		int ma = ask(m);
		int mb = ask((n / 2) + m);
		if (ma == mb) {
			ans(m);
			return 0;
		}
		if (sign(ma - mb) == sign(a - b)) {
			l = m;
		} else {
			r = m;
		}
	}
	ans(r);
	return 0;
}

