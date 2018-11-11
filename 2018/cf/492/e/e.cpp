#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pnt {
	long long x;
	long long y;
	int n;
	Pnt() : x(0), y(0) {}
	Pnt(long long x, long long y): x(x), y(y), n(-1) {}
	Pnt operator + (Pnt p) const {
		return Pnt(x + p.x, y + p.y);
	}
	Pnt operator - (Pnt p) const {
		return Pnt(x - p.x, y - p.y);
	}
	bool operator < (Pnt p) const {
		return (x * p.y - y * p.x) < 0;
	}
	long long len2() const {
		return x * x + y * y;
	}
};

struct Joint {
	Pnt v;
	// [l, r)
	int l;
	int r;
	Joint(Pnt v, int l, int r): v(v), l(l), r(r) {}
};

long long MAX_MODULO = 1'000'000;
long long MAX_MODULO_2 = MAX_MODULO * MAX_MODULO;
long long BORDER = 1'500'000;
long long BORDER_2 = BORDER * BORDER;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Pnt> p(n);
	vector<int> a(n, 1);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].n = i;
		if ((p[i].x < 0) || (p[i].x == 0 && p[i].y < 0)) {
			p[i].x = -p[i].x;
			p[i].y = -p[i].y;
			a[i] *= -1;
		}
	}

	sort(p.begin(), p.end());

	Pnt pos(0, 0);
	vector<Joint> v;
	int prev = 0;
	for (int i = 0; i < n; ++i) {
		if (min((pos + p[i]).len2(), (pos - p[i]).len2()) > MAX_MODULO_2) {
			v.emplace_back(pos, prev, i);
			pos = Pnt(0, 0);
			prev = i;
		}
		if ((pos - p[i]).len2() < (pos + p[i]).len2()) {
			a[p[i].n] *= -1;
			pos = pos - p[i];
		} else {
			pos = pos + p[i];
		}
	}

	/*
	cerr << "sorted points & coef" << endl;
	for (int i = 0; i < n; ++i) {
		cerr << "a " << ((a[p[i].n] == -1) ? "-1" : " 1")  << " n " << p[i].n << " " << p[i].x << " " << p[i].y << endl;
	}
	*/


	v.emplace_back(pos, prev, n);
	vector<int> b(v.size(), 1);

	Pnt sum;
	for (int i = 0; i < (1 << v.size()); ++i) {
		sum = Pnt(0, 0);
		for (int j = 0; j < v.size(); ++j) {
			b[j] = (((1 << j) & i) > 0) ? -1 : 1;
			if (b[j] == -1) {
				sum = sum - v[j].v;
			} else {
				sum = sum + v[j].v;
			}
		}
		if (sum.len2() <= BORDER_2) {
			break;
		}
	}

	/*
	cerr << "n left for brute force " << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		cerr << ((b[i] == -1) ? "-1" : " 1") << " l " << v[i].l << " r " << v[i].r << ": " << v[i].v.x << " " << v[i].v.y << endl;
	}

	cerr << "expected pos " << sum.x << " " << sum.y << endl;
	*/

	for (int i = 0; i < v.size(); ++i) {
		for (int j = v[i].l; j < v[i].r; ++j) {
			a[p[j].n] *= b[i];
		}
	}

	/*
	for (int i = 0; i < n; ++i) {
		cerr << "a " << ((a[p[i].n] == -1) ? "-1" : " 1")  << " n " << p[i].n << " " << p[i].x << " " << p[i].y << endl;
	}
	*/

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}