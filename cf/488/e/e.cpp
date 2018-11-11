#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

const double PI  =3.141592653589793238463;

typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply (const vector<long long> & a, const vector<long long> & b, vector<long long> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = (long long)(fa[i].real() + 0.5);
}

// L and R inclusive
void solve(const vector<long long> &a, int L, int R, vector<long long> &ans) {
	if (R - L + 1 < 16) {
		for (int l = L; l <= R; ++l) {
			for (int r = l; r <= R; ++r) {
				int sum = 0;
				for (int j = l; j <= r; ++j) {
					sum += a[j];
				}
				++ans[sum];
			}
		}
		return;
	}
	int mid = (R + L) / 2;
	solve(a, L, mid - 1, ans);
	solve(a, mid + 1, R, ans);
	vector<long long> left((R - L) / 2 + 2, 0);
	long long sum = 0;
	for (int i = mid; i >= L; --i) {
		sum += a[i];
		++left[sum];
	}
	sum = 0;
	vector<long long> right((R - L) /  2 + 2, 0);
	for (int i = mid + 1; i <= R; ++i) {
		++right[sum];
		sum += a[i];
	}
	++right[sum];

	vector<long long> tmp;
	multiply(left, right, tmp);
	/*
	cerr << L << " " << R << endl;
	cerr << "mid " << mid << endl;
	for (int i = 0; i < left.size(); ++i) {
		cerr << left[i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < right.size(); ++i) {
		cerr << right[i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < tmp.size(); ++i) {
		cerr << tmp[i] << " ";
	}
	cerr << endl;
	*/
	for (int i = 0; i < min(tmp.size(), ans.size()); ++i) {
		ans[i] += tmp[i];
	}


}

int main() {
	long long n, x;
	cin >> n >> x;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		a[i] = (c < x) ? 1 : 0;
	}
	vector<long long> ans(n + 1, 0);
	solve(a, 0, a.size() - 1, ans);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}