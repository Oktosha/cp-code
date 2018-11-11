#include <iostream>

using namespace std;

int sum_nbrs(int x) {
	int ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main() {
	int k;
	cin >> k;
	int n = 1;
	int j = 0;
	while (j < k) {
		++n;
		if (sum_nbrs(n) == 10) {
			++j;
		}
	}
	cout << n << endl;
	return 0;
}