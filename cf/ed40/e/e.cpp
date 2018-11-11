#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pipe {
	long double t;
	long double a;
	bool operator < (Pipe p) const {
		return t < p.t;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	long double T;
	cin >> T;
	vector<Pipe> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i].a;
		
	} 
	for (int i = 0; i < N; ++i) {
		cin >> a[i].t;
	}
	sort(a.begin(), a.end());
	/*
	for (int i = 0; i < a.size(); ++i) {
		cerr << "a " <<  a[i].a << " t " << a[i].t << endl;
	}
	cerr << endl;
	*/
	cout.precision(10);
	if ((a[0].t > T) || (a[N - 1].t < T)) {
		cout << fixed << 0.0 << endl;
		return 0;
	}
	long double total_v = 0;
	long double weighted_t = 0;
	for (int i = 0; i < N; ++i) {
		total_v += a[i].a;
		weighted_t += a[i].a * a[i].t;
	}
	long double cur_t = weighted_t / total_v;
	if (cur_t == T) {
		cout << fixed << total_v << endl;
		return 0;
	}
	// cerr << "start t " << cur_t << endl;
	cout.precision(15);
	if (T > cur_t) {
		// cerr << "need to increase temperature" << endl;
		for (int i = 0; i < N; ++i) {
			long double next_w = weighted_t - a[i].a * a[i].t;
			long double next_v = total_v - a[i].a;
			long double next_t = next_w / next_v;
			if (next_t >= T) {
				long double x = (T * next_v - next_w) / (a[i].t - T);
				cout << fixed << (next_v + x) << endl;
				return 0;
			}
			weighted_t = next_w;
			total_v = next_v;
			cur_t = next_t;
		}
	} else {
		// cerr << "need to decrease temperature" << endl;
		for (int i = N - 1; i >= 0; --i) {
			long double next_w = weighted_t - a[i].a * a[i].t;
			long double next_v = total_v - a[i].a;
			long double next_t = next_w / next_v;
			/*
			cerr << i << " " << next_t << endl;
			cerr << "w " << next_w << endl;
			cerr << "v " << next_v << endl;
			*/
			if (next_t <= T) {
				long double x = (T * next_v - next_w) / (a[i].t - T);
				cout << fixed << (next_v + x) << endl;
				return 0;
			}
			weighted_t = next_w;
			total_v = next_v;
			cur_t = next_t;
		}
	}

	return 0;
}
