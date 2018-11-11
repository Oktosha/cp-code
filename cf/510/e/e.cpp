#include <bits/stdc++.h>

using namespace std;

const long long MODULO = 998244353;
long long reverse(long long x) {
	
}
struct Element {
	int r;
	int c;
	long long a;
	Element(int r, int c, long long a): r(r), c(c), a(a) {}
	bool operator < (Element e) {
		return a < e.a;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<Element> element;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			long long a;
			cin >> a;
			element.emplace_back(i, j, a);
		}
	}
	int r, c;
	cin >> r >> c;
	sort(element.begin(), element.end());
	long long cum_sum_prev_level = 0;
	int n_prev_level = 0;
	int a_prev_level = -1;

	long long cum_sum_cur = 0;
	int n_cur = 0;
	int a_cur = 0; 
	for (auto e : element) {
		if (e.a > a_cur) {
			a_prev_level = a_cur;
			n_prev_level = sum(n_cur, n_prev_level);
			cum_sum_prev_level = sum(cum_sum_cur, cum_sum_prev_level);

			a_cur = e.a;
			n_cur = 0;
			cum_sum_cur = 0;
		}
		long long ans = mult(cum_sum_prev_level, reverse(n_prev_level));
		inc(n_cur);
		cum_sum_cur = sum(cum_sum_cur, ans);

		if (e.r == r && e.c == c) {
			cout << ans << endl;
			return 0;
		}
	}

	return 0;
}
