#include <iostream>
using namespace std;

long long MODULO = 1'000'000'009;

long long pow(long long x, long long n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	long long t = pow(x, n / 2);
	t = (t * t) % MODULO;
	return (t * ((n % 2 == 1) ? x : 1LL)) % MODULO;
}

long long opposite(long long x) {
	return pow(x, MODULO - 2);
}

long long geom_progression(long long q, long long n) {
	if (q == 1) {
		return n;
	}
	long long up = (MODULO + 1 - pow(q, n)) % MODULO;
	long long down = (MODULO + 1 - q) % MODULO;
	return (up * opposite(down)) % MODULO;
}

int main() {
	long long n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	long long c = pow(a, n);
	long long q = (opposite(a) * b) % MODULO;
	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = (MODULO + ans + c * (s[i] == '+' ? 1LL : -1LL)) % MODULO;
		c = (c * q) % MODULO;
	}
	long long Q = pow(q, k);
	long long sum = geom_progression(Q, (n + 1) / k);
	cout << (ans * sum) % MODULO << endl;
	return 0;
}
