#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
	long long t;
	int a;
	int n;
	bool operator < (Task other) const {
		return t < other.t;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	long long T;
	cin >> n >> T;
	vector<Task> task(n);
	for (int i = 0; i < n; ++i) {
		cin >> task[i].a;
		cin >> task[i].t;
		task[i].n = i + 1;
	}
	sort(task.begin(), task.end());
	/*
	cerr << "sorted" << endl;
	for (int i = 0; i < n; ++i) {
		cerr << task[i].a << " " << task[i].t << " " << task[i].n << endl;
	}
	cerr << endl;
	*/

	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		long long solving_time = 0;
		int n_solved = 0;
		for (int i = 0; i < n && n_solved < m; ++i) {
			if (task[i].a >= m) {
				solving_time += task[i].t;
				++n_solved;
			}
		}
		/*
		cerr << "m " << m << endl;
		cerr << "solving time " << solving_time << endl;
		cerr << "n_solved " << n_solved << endl;
		*/
		if ((n_solved < m) || (solving_time > T)) {
			r = m;
		} else  {
			l = m;
		}
	}
	cout << l << endl << l << endl;
	int n_solved = 0;
	for (int i = 0; i < n && n_solved < l; ++i) {
		if (task[i].a >= l) {
			cout << task[i].n << " ";
			++n_solved;
		}
	}
	cout << endl;
	return 0;
}