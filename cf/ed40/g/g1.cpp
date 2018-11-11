#include <iostream>
#include <vector>
#include <deque>

struct A {
	long long a;
	int pos;
	A(long long a, int pos): a(a), pos(pos) {}
};

using namespace std;

long long INF = (long long)(1e18) + 500000LL * 1000000000LL + 100500LL;

bool is_possible(vector<long long> &a, long long x, long long k, int r) {
	cerr << "is possible " << x << endl;
	int n = a.size();
	vector<long long> add(n + r + 2, 0);
	long long cum_sum = 0;
	for (int i = r; i < n + r; ++i) {
		add[i] = max(x - (a[i - r] + cum_sum), 0LL);
		cerr << i << " " << add[i] << endl;
		cerr << cum_sum << endl;
		cum_sum += add[i];
		cum_sum -= add[i - r];
		k -= add[i];
		if (k < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	// cerr << INF << endl;
	int n, r;
	long long k;
	cin >> n >> r >> k;
	vector<long long> a(n + 2 * r + 2, 0);
	for (int i = r; i < n + r; ++i) {
		cin >> a[i];
	}
	vector<long long> sum(n + 2 * r + 2, 0);
	long long cur_sum = 0;
	for (int i = 0; i < 2 * r + 1; ++i) {
		sum[r] += a[i];
	}
	for (int i = r + 1; i < n + r; ++i) {
		sum[i] = sum[i - 1] - a[i - r - 1] + a[i + r];
	}
	/*
	cerr << "r " << r << endl;
	cerr << "sum lg" << endl;
	for (int i = 0; i < sum.size(); ++i) {
		cerr << sum[i] << " ";
	}
	cerr << endl;
	*/
	sum.erase(sum.begin(), sum.begin() + r);
	sum.resize(n);
	/*
	cerr << "sum" << endl;
	for (int i = 0; i < sum.size(); ++i) {
		cerr << sum[i] << " ";
	}
	cerr << endl;
	*/
	a.erase(a.begin(), a.begin() + r);
	a.resize(n);
	/*
	for (int i = 0; i < a.size(); ++i) {
		cerr << a[i] << " ";
	}
	cerr << endl;
	*/


	long long L = 0;
	long long R = INF;
	while (R - L > 1) {
		long long M = L + ((R - L) / 2);
		if (is_possible(sum, M, k, r)) {
			L = M;
		} else {
			R = M;
		}
	}
	cout << L << endl;
	return 0;
}