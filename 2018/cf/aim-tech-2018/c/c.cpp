#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
	int x0, y0, x1, y1;
};

const int INF = 1'000'000'500;

struct Event {
	int x;
	int t; //1 + rectangle opens, -1 rectangle ends
	int n;
	bool operator < (Event e) const {
		return x < e.x || ((x == e.x) && (t > e.t));
	}
	Event(int x, int t, int n): x(x), t(t), n(n) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Rectangle> a(N);
	vector<Event> events_x;
	for (int i = 0; i < N; ++i) {
		cin >> a[i].x0 >> a[i].y0 >> a[i].x1 >> a[i].y1;
		events_x.emplace_back(a[i].x0, 1, i);
		events_x.emplace_back(a[i].x1, -1, i);
	}
	sort(events_x.begin(), events_x.end());
	int ans_x = INF;
	int ans_y = INF;


	vector<bool> active(N, false);
	int balance_x = 0;
	for (auto e_x : events_x) {
		balance_x += e_x.t;
		// cerr << "balance x: " << balance_x << endl;
		active[e_x.n] = (e_x.t == 1);
		if (balance_x >= N - 1) {
			vector<Event> events_y;
			for (int i = 0; i < N; ++i) {
				if (active[i]) {
					events_y.emplace_back(a[i].y0, 1, i);
					events_y.emplace_back(a[i].y1, -1, i);
				}
			}
			sort(events_y.begin(), events_y.end());
			int balance_y = 0;
			for (auto e_y : events_y) {
				balance_y += e_y.t;
				if (balance_y >= N - 1) {
					ans_x = e_x.x;
					ans_y = e_y.x;
				}
			}
		}
	}

	cout << ans_x << " " << ans_y << endl;
	return 0;
}
