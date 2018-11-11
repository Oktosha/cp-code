#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pos {
	int r;
	int c;
};

struct Move {
	Move(Pos p, int c): p(p), c(c) {}
	Pos p;
	int c;
};

void cerr_parking_state(const vector<vector<int>> &car) {
	cerr << "Current parking state" << endl;
	for (int i = 0; i < car[0].size(); ++i) {
		cerr << car[0][i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < car[1].size(); ++i) {
		cerr << car[1][i] << " ";
	}
	cerr << endl;
}

void move_to_parking_slots(vector<vector<int>> &car, const vector<vector<Pos>> &pos, vector<Move> &ans) {
	for (int i = 0; i < car[1].size(); ++i) {
		int c = car[1][i];
		if (c != 0 && c == car[0][i]) {
			ans.emplace_back(pos[0][i], c);
			car[1][i] = 0;
		}
	}
}

int rotate(vector<vector<int>> &car, const vector<vector<Pos>> &pos, vector<Move> &ans) {
	int l = car[1].size();
	auto zero_it = find(car[1].begin(), car[1].end(), 0);
	if (zero_it == car[1].end())
		return -1;
	int i_z = zero_it - car[1].begin();
	bool are_cars = false;
	for (int p = (i_z + 1) % l; p != i_z; p = (p + 1) % l) {
		if (car[1][p] != 0) {
			are_cars = true;
			int prev = (l + p - 1) % l;
			ans.emplace_back(pos[1][prev], car[1][p]);
			car[1][prev] = car[1][p];
			car[1][p] = 0;
		}
	}
	return (are_cars ? 1 : 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> car(2, vector<int>(2 * n, 0));
	vector<vector<Pos>> pos(2, vector<Pos>(2 * n));
	for (int i = 0; i < n; ++i) {
		pos[0][i].r = 1;
		pos[0][i].c = i + 1;
		pos[1][i].r = 2;
		pos[1][i].c = i + 1;
		pos[0][n + i].r = 4;
		pos[0][n + i].c = n - i;
		pos[1][n + i].r = 3;
		pos[1][n + i].c = n - i;
	}
	/*
	for (int i = 0; i < 2 * n; ++i) {
		cerr << pos[0][i].r << " " << pos[0][i].c << " ";
	}
	cerr << endl;
	for (int i = 0; i < 2 * n; ++i) {
		cerr << pos[1][i].r << " " << pos[1][i].c << " ";
	}
	cerr << endl;
	*/
	int k;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		cin >> car[0][i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> car[1][i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> car[1][n + n - i - 1];
	}
	for (int i = 0; i < n; ++i) {
		cin >> car[0][n + n - i - 1];
	}

	vector<Move> ans;
	int status;

	do {
		// cerr << "Parking..." << endl;
		move_to_parking_slots(car, pos, ans);
		// cerr_parking_state(car);
		// cerr << "Rotating..." << endl;
		status = rotate(car, pos, ans);
		// cerr_parking_state(car);
	} while (status == 1);

	if (status == -1) {
		cout << -1 << endl;
	} else {
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i].c << " " << ans[i].p.r  << " " << ans[i].p.c << "\n";
		}
	}
	
	return 0;
}