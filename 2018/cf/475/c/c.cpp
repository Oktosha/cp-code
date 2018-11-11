#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;

struct Elem {
	long long w;
	long long h;
	long long c;
	bool operator < (Elem e) const {
		return h < e.h || (h == e.h && w < e.w);
	}
};

long long divide_product(long long a, long long b, long long divisor) {
	long long d2 = divisor / gcd(a, divisor);
	if (b % d2 != 0) {
		// cout << a << " * " << b << " % " << divisor << " != 0" << endl;
		return -1;
	}
	long long a1 = a / gcd(a, divisor);
	long long b1 = b / d2;
	if (to_string(a1).size() + to_string(b1).size() > 14) {
		return -1;
	}
	return a1 * b1;
}


int main() {
	ios_base::sync_with_stdio(false);
	unordered_set<long long> unique_w;
	unordered_set<long long> unique_h;
	int n;
	cin >> n;
	vector<Elem> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].w >> a[i].h >> a[i].c;
		unique_w.insert(a[i].w);
		unique_h.insert(a[i].h);
	}
	int W = unique_w.size();
	int H = unique_h.size();
	if (W * H != n) {
		cout << 0 << "\n";
		return 0;
	}
	sort(a.begin(), a.end());
	long long x00 = a[0].c;
	long long gcd_xi0 = x00;
	long long gcd_x0j = x00;
	for (int i = 1; i < H; ++i) {
		for (int j = 1; j < W; ++j) {
			long long xi0 = a[i * W].c;
			long long x0j = a[j].c;
			gcd_xi0 = gcd(gcd_xi0, xi0);
			gcd_x0j = gcd(gcd_x0j, x0j);
			if ((divide_product(xi0, x0j, x00) != a[i * W + j].c)) {
				cout << 0 << "\n";
				return 0;
			}	
		}
	}

	/*
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			long long w = a[i * W + j].w;
			long long h = a[i * W + j].h;
			long long c = a[i * W + j].c;
			cerr << "w " << w << " h " << h << " c " << c << "; ";
		}
		cerr << endl;
	}
	*/
	

	int ans = 0;
	for (long long d = 1; d * d <= x00; ++d) {
		if (x00 % d == 0) {
			long long d1 = x00 / d;
			if ((gcd_xi0 % d == 0) && (gcd_x0j % d1 == 0)) {
				++ans;
			}
			if ((d1 != d) && (gcd_xi0 % d1 == 0) && (gcd_x0j % d == 0)) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
