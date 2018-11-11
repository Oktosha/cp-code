#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int BEFORE = 0;
const int AFTER = 1;

void calc(int v, const vector<vector<int>> &g, 
	vector<array<array<vector<int>, 2>, 2>> &a, vector<array<bool, 2>> &can_die) {
	int can_both = -1;
	vector<int> before;
	vector<int> after;
	for (auto u : g[v]) {
		calc(u, g, a, can_die);
		if (can_die[u][BEFORE] == false && can_die[u][AFTER] == false) {
			return;
		}
		if (can_both == -1 && can_die[u][BEFORE] && can_die[u][AFTER]) {
			can_both = u;
			continue;
		}
		if (can_die[u][BEFORE]) {
			before.push_back(u);
		} else {
			after.push_back(u);
		}
	}
	if (can_both == -1) {
		if (g[v].size() % 2 != before.size() % 2) {
			can_die[v][BEFORE] = true;
			a[v][BEFORE][BEFORE] = before;
			a[v][BEFORE][AFTER] = after;
		} else {
			can_die[v][AFTER] = true;
			a[v][AFTER][BEFORE] = before;
			a[v][AFTER][AFTER] = after;
		}
		return;
	}
	can_die[v][BEFORE] = true;
	can_die[v][AFTER] = true;
	a[v][BEFORE][BEFORE] = before;
	a[v][BEFORE][AFTER] = after;
	a[v][AFTER][BEFORE] = before;
	a[v][AFTER][AFTER] = after;
	if (g[v].size() % 2 != before.size() % 2) {
		a[v][BEFORE][AFTER].push_back(can_both);
		a[v][AFTER][BEFORE].push_back(can_both);
	} else {
		a[v][BEFORE][BEFORE].push_back(can_both);
		a[v][AFTER][AFTER].push_back(can_both);
	}
}

void print_ans(int v, int when, vector<array<array<vector<int>, 2>, 2>> &a) {
	for (int u : a[v][when][BEFORE]) {
		print_ans(u, BEFORE, a);
	}
	cout << v << "\n";
	for (int u : a[v][when][AFTER]) {
		print_ans(u, AFTER, a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		g[v].push_back(i);
	}
	vector<array<bool, 2>> can_die(n + 1, {false, false});

	//a[i][BEFORE][AFTER] <- vector of children of the vertex i
	// which should die after it when it dies before it's parent
	vector<array<array<vector<int>, 2>, 2>> a(n + 1);

	int root = g[0][0];
	calc(root, g, a, can_die);
	if (can_die[root][AFTER]) {
		cout << "YES\n";
		print_ans(root, AFTER, a);
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
