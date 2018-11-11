#include <iostream>
#include <vector>

using namespace std;

long long MAX_N = 500000;
long long MAX_K = (long long)(1e18);
long long MAX_A = (long long)(1e9);
long long INF = MAX_A * MAX_N + MAX_K + 100500;

bool is_possible(const vector<long long> &s, int r, long long k, long long M) {
	// cerr << "Is possible " << M  << endl;
	long long added_sum = 0;
	int n = s.size();
	vector<long long> a(n);
	int start = -r;
	int end = r;
	for (int i = 0; i < n; ++i) {
		/*
		cerr << i << " seg from " << start << " to " << end << endl;
		cerr << "Nearby add: ";
		for (int j = max(start, 0); j <= min(n - 1, end); ++j) {
			cerr << a[j] << " ";
		}
		cerr << endl;
		cerr << "sum " << added_sum << endl;
		cerr << "val " << s[i] << endl;
		*/
		if (added_sum + s[i] < M) {
			long long delta =  M - added_sum - s[i];
			// cerr << "delta " << delta << endl;
			a[min(i + r, n - 1)] += M - added_sum - s[i];
			k -= delta;
			if (k < 0) {
				return false;
			}
			added_sum += delta;
		}
		if (start >= 0) {
				added_sum -= a[start];
			}
		++start;
		++end;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	// reading
	int n, r;
	long long k;
	cin >> n >> r >> k;
	vector<long long> a(n + 2 * r, 0);
	for (int i = r; i < n + r; ++i) {
		cin >> a[i];
	}

	// computing s
	vector<long long> s(n + 2 * r, 0);
	for (int i = 0; i < 2 * r + 1; ++i) {
		s[r] += a[i];
	}
	for (int i = r + 1; i < n + r; ++i) {
		s[i] = s[i - 1] - a[i - r - 1] + a[i + r];
	}

	s.erase(s.begin(), s.begin() + r);
	s.resize(n);

	/*
	cerr << "s" << endl;
	for (int i = 0; i < n; ++i) {
		cerr << s[i] << " ";
	}
	cerr << endl;
	*/

	// binsearch
	long long L = 0;
	long long R = INF;
	while(R - L > 1) {
		long long M = L + ((R - L) / 2);
		if (is_possible(s, r, k, M)) {
			L = M;
		} else {
			R = M;
		}
	}
	cout << L << endl;
	return 0;
}