#include <bits/stdc++.h>

using namespace std;

struct Event {
	Event(int value, int x, int t): value(value), x(x), t(t) {}
	int value;
	int x;
	int t; //t = 1 <- addition, -1 -> deletion

	bool operator < (Event e) const {
		return x < e.x || (x == e.x && t > e.t);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> a(N, 0);
	vector<int> l(Q + 1, N);
	vector<int> r(Q + 1, -1);
	int pos_zero = -1;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
		if (a[i] == 0) {
			pos_zero = i;
		}
	}
	l[1] = 0;
	r[1] = N - 1;

	if (l[Q] > r[Q]) {
		if (pos_zero == -1) {
			cout << "NO" << endl;
			return 0;
		}
		l[Q] = pos_zero;
		r[Q] = pos_zero;
	}
	
	vector<Event> ev;
	for (int i = 1; i <= Q; ++i) {
		ev.emplace_back(i, l[i], 1);
		ev.emplace_back(i, r[i], -1);
	}
	sort(ev.begin(), ev.end());

	int pos = 0;
	vector<int> ans(N, 0);
	set<int> active;
	for (int i = 0; i < N; ++i) {
		while ((pos < ev.size()) && ev[pos].x < i) {
			if (ev[pos].t == 1) {
				active.insert(ev[pos].value);
			} else {
				active.erase(ev[pos].value);
			}
			++pos;
		}
		while((pos < ev.size()) && ev[pos].x == i && ev[pos].t == 1) {
			active.insert(ev[pos].value);
			++pos;
		}
		ans[i] = *active.rbegin();
	}

	bool is_equal = true;
	for (int i = 0; i < N; ++i) {
		is_equal = is_equal && (a[i] == 0 || ans[i] == a[i]);
	}

	if (is_equal) {
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
