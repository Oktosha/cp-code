#include <iostream>
#include <cmath>

using namespace std;

bool is_reachable(long long y, long long p) {
	for (long long i = 2; i <= min((long long)sqrt(y) + 1, p); ++i) {
		if (y % i == 0)
			return true;
	}
	return false;
}
int main() {
	long long p, y;
	cin >> p >> y;
	while(y > p && is_reachable(y, p)) {
		--y;
	}
	if (y == p) {
		cout << -1 << endl;
	} else {
		cout << y << endl;
	}
	return 0;
}