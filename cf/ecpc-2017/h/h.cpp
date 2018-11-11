#include <iostream>
#include <cmath>
#include <numeric>
#include <utility>

using namespace std;

long long my_stoll(string s) {
	long long ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		ans *= 10;
		ans += (s[i] - '0');
	}
	return ans;
}

pair<string, string> divide(long long x) {
	string s = to_string(x);
	return {s.substr(0, s.size() / 2), s.substr(s.size() / 2, s.size())};
}
long long left(long long x) {
	return my_stoll(divide(x).first);
}

long long right(long long x) {
	return my_stoll(divide(x).second);
}

bool is_nice(long long x) {
	// cerr << "is_nice " << x << endl;
	return (right(x) != 0) && (gcd(left(x), right(x)) > 1);
}

long long construct(long long left, long long right, long long r_len) {
	long long ten = 1;
	for (int i = 0; i < r_len; ++i) {
		ten *= 10ll;
	}
	return (left * ten + right);
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("halfnice.in", "r", stdin);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		long long a, b;
		cin >> a >> b;
		long long max_nice = -1;

		for (long long c = max(a, b - 2000); c <= b; ++c) {
			if (is_nice(c)) {
				max_nice = max(max_nice, c);
			}
		}

		for (long long c = a; c <= min(b, a + 2000); ++c) {
			if (is_nice(c)) {
				max_nice = max(max_nice, c);
			}
		}

		if (left(b) % 2 != 0 && left(b) > 1) {
			long long len = to_string(b).size();
			long long l_len = len / 2;
			long long r_len = (len + 1) / 2;

			long long even_x = construct(left(b), 0, r_len) - 2ll;
			if (even_x >= a) {
				max_nice = max(max_nice, even_x);
			}
			long long ya_x = construct(left(b), 0, r_len) - 1ll;
			if (is_nice(ya_x) && ya_x >= a) {
				max_nice = max(ya_x, max_nice);
			}

			for (long long p = 3; p <= sqrt(left(b)) + 2; ++p) {
				if (left(b) % p == 0) {
					long long c = construct(left(b), right(b) - (right(b) % p), r_len);
					if (is_nice(c) && c >= a) {
						max_nice = max(c, max_nice);
					}
				}
			}
			long long c = construct(left(b), right(b) - (right(b) % left(b)), r_len);
			if (is_nice(c) && (c >= a)) {
				max_nice = max(c, max_nice);
			}

		}

		cout << "Case " << test << ": ";
		if (max_nice == -1) {
			cout << "impossible" << "\n";
		} else {
			cout << max_nice << "\n";
		}
	}
	return 0;
}
