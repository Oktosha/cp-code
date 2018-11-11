#include <iostream>

double INF = 100500;
using namespace std;
int main() {
	int n;
	double m;
	cin >> n >> m;
	double ans = INF;
	for (int i = 0; i < n; ++i) {
		double a, b;
		cin >> a >> b;
		ans = min(ans, a * m / b);
	}
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}
