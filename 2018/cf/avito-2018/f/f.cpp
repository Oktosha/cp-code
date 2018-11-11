#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Event {
	int t; // 1 -> begin; -1 -> end
	long long x;
	Event(int t, long long x): t(t), x(x) {}
	bool operator < (Event e) const {
		return x < e.x || ((x == e.x) && (t > e.t));
	}
}

long long shortest_dist(long long x, long long y, long long L) {
	return min(abs(x - y), L - abs(x - y));
}

int bound_find(int a, int l, int r, vector<long long> &b, long long L, long long dist) {
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (shortest_dist(a, b[(m + b.size()) % b.size()], L) <= dist) {
			r = m;
		} else {
			l = m;
		}
	}
	return r;
}

bool is_possible(long long dist, 
	             const vector<long long> &a, const vector<long long> &b,
	             const vector<int> &nearest,
	             long long L) {
	int n = a.size();
	vector<Event> e;
	for (int i = 0; i < n; ++i) {
		int l = bound_find(a[i], nearest[i] - n, nearest[i], b);
		if (((l + 3 * n) % n) == ((nearest[i] + 1) % n)) {
			e.emplace_back(1, 0);
			e.emplace_back(-1, n - 1);
			continue;
		}
		int r = find_r(a[i], nearest[i], b);
		l -= i;
		r -= i;
		while (l < 0) {
			l += n;
			r += n;
		}
		e.emplace_back(1, l);
		e.emplace_back(-1, min(r, n - 1));
		if (r >= n) {
			e.emplace_back(1, 0);
			e.emplace_back(-1, r - n);
		}
	}
	sort(e.begin(), e.end());
	int balance = 0;
	int max_balance = 0;
	for (int i = 0; i < e.size(); ++i) {
		balance += e[i].t;
		max_balance = max(max_balance, balance);
	}
	return max_balance == n;
	/*
	int l = nearest;
	while((shortest_dist(a[0], b[(n + l - 1) % n]) <= dist) && (l > (nearest - n))){
		--l;
	}
	int r = nearest;
	while((shortest_dist(a[0], b[(r + 1) % n]) <= dist) && (r < (l + nearest))) {
		++r;
	}
	*/
}
int main() {
	int n;
	long long L;
	cin >> n >> L;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<long long> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// Checking for zero
	// Also it will deal with L = 1
	bool ans_is_zero = true;
	for (int i = 0; i < n; ++i) {
		ans_is_zero = (ans_is_zero) && (a[i] == b[i]);
	}
	if (ans_is_zero) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> nearest(n);
	nearest[0] = 0;
	while(shortest_dist(a[0], b[(nearest[0] + 1) % n], L) < shortest_dist(a[0], b[nearest[0]], L)) {
		nearest[0] = (nearest[0] + 1) % n;
	}
	while(shortest_dist(a[0], b[(n + nearest[0] - 1) % n], L) < shortest_dist(a[0], b[nearest[0]], L)) {
		nearest[0] = (n + nearest[0] - 1) % n;
	}
	long long lower_bound = shortest_dist(a[0], b[nearest[0]], L);
	for (int i = 1; i < n; ++i) {
		nearest[i] = nearest[i - 1];
		while(shortest_dist(a[i], b[(nearest[i] + 1) % n], L) < shortest_dist(a[i], b[nearest[i]], L)) {
			nearest[i] = (nearest[i] + 1) % n;
		}
		lower_bound = max(lower_bound, shortest_dist(a[i], b[nearest[i]], L));
	}

	long long l = lower_bound - 1; // this distance is too small
	long long r = L / 2; // this distance is defenetly enough
	while (r - l > 1) {
		long long m = (r + l + 1) / 2;
		if (is_possible(m, a, b, nearest, L)) {
			r = m;
		} else {
			l = m;
		}
	}

	cout << r << endl;

	return 0;
}