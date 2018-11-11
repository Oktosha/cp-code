#include <iostream>

using namespace std;

const long long INF = 1'000'000'000'000;

int main() {
	long long n;
	cin >> n;
	long long ans = -1;
	long long ans_time = INF;
	for (long long i = 0; i < n; ++i) {
		long long cur_time = INF;
		long long x;
		cin >> x;
		x = max(x - i, 0LL);
		if (x % n == 0) {
			cur_time = i + x;
		} else {
			cur_time = i + n * (1 + (x / n));
		}
		if (cur_time < ans_time) {
			ans_time = cur_time;
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
