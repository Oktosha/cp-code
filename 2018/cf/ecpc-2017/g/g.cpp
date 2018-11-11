#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		long double n, r, k;
		cin >> n >> r >> k;
		long double a = M_PI / k;
		// cerr << "a " << a << endl;
		long double b = (1.0 / cos(a));
		b = b * b;
		// cerr << "b " << b << endl;
		long double geom_sum = (pow(b, n) - 1.0) / (b - 1.0);
		// cerr << "geom_sum " << geom_sum << endl;
		long double sp = r * r * tan(a) * k;
		long double so = r * r * M_PI;
		// cerr << sp << " " << so << endl;
		cout << fixed;
		cout.precision(5);
		cout << "Case " << test << ": " << geom_sum * (sp - so) << "\n";
	}
	return 0;
}