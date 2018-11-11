#include <iostream>

using namespace std;

struct Point {
	long long x;
	long long y;
	Point(): x(0), y(0) {}
	Point(long long x, long long y): x(x), y(y) {}
	Point operator - (Point p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator + (Point p) const {
		return Point(x + p.x, y + p.y);
	}
	long long len2() const {
		return x * x + y * y;
	}
};

struct Triangle {
	long long a;
	long long b;
	long long c;
}

typedef Point pt;

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<Point> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	convex_hull(a);
	vector<Point> b(N);
	for (int i = 0; i < M; ++i) {
		cin >> b[i].x >> b[i].y;
	}
	convex_hull(b);
	if (a.size() != b.size()) {
		cout << "NO";
		return 0;
	}

	auto a_t = create_triangles(a);
	vector<Hash> a_h(a.size());
	auto b_t = create_triangles(b);


	return 0;
}
