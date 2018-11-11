#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pnt {
	long long x;
	long long y;
	bool operator < (Pnt p) const {
		return y < p.y || (y == p.y && x < p.x);
	}
};

istream& operator >> (istream &is, Pnt &p) {
	is >> p.x >> p.y;
	return is;
}

int main() {
	// reading square
	vector<Pnt> p(4);
	for (int i = 0; i < 4; ++i) {
		cin >> p[i];
	}
	long long A = max(abs(p[1].x - p[0].x), abs(p[1].y - p[0].y));
	sort(p.begin(), p.end());
	long long xa = p[0].x;
	long long ya = p[0].y;

	// reading rhomb
	for (int i = 0; i < 4; ++i) {
		cin >> p[i];
		p[i].x = -p[i].x;
		p[i].y = -p[i].y;
	}
	long long B = abs(p[1].x - p[0].x);
	sort(p.begin(), p.end());
	long long xb = p[0].x;
	long long yb = p[0].y;

	// the leftiest from the lowest points of the minkovsly sum
	long long X = xa + xb;
	long long Y = ya + yb;

	int k = 0;
	int lim[8] = {A, B, A, B, A, B, A, B};
	int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < lim[j]; ++i) {
			X += dx[j];
			Y += dy[j];
			cerr << X << " " << Y << endl;
			if ((X == 0) && (Y == 0)) {
				cout << "Yes" << endl;
				return 0;
			}
			if ((X == 0) && (Y > 0)) {
				++k;
			}
		}
	}

	if (k == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
