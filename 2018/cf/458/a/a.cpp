#include <iostream>
#include <cmath>

using namespace std;

long long INF = 1000007;

bool is_perfect_square(long long x) {
	if (x < 0) {
		return false;
	}
	if (x == 0) {
		return true;
	}
	long long root = sqrt(x);
	return root * root == x;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long ans = -INF;
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		if (!is_perfect_square(x)) {
			ans = max(x, ans);
		}
	}
	cout << ans << endl;
	return 0;
}
