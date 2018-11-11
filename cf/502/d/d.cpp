#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> w;
int N;
short wu(int x, int y) {
	short ans = 0;
	for (int i = 0; i < N; ++i) {
		bool bit = (~(x ^ y)) & (1 << i);
		ans += bit ? w[i] : 0;
	}
	return ans;
}

struct Counter {
	int ans;
	short wu;
	Counter(int ans, int wu): ans(ans), wu(wu) {}
	bool operator < (Counter c) const {
		return wu < c.wu;
	}
};

const int MAX_REQUEST = 101;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int M, Q;
	cin >> M >> Q;
	w.resize(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
	}
	reverse(w.begin(), w.end());

	int sz = 1 << N;
	vector<int> cnt(sz);
	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;
		++cnt[stoi(s, 0, 2)];
	}

	vector<vector<int>> calc(sz, vector<int>(MAX_REQUEST, 0));
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			int cur_wu = wu(i, j);
			if (cur_wu < MAX_REQUEST)
				calc[i][cur_wu] += cnt[j];
		}
		for (int j = 1; j < calc[i].size(); ++j) {
			calc[i][j] += calc[i][j - 1];
		}


	}

	for (int i = 0; i < Q; ++i) {
		string s;
		cin >> s;
		int x = stoi(s, 0, 2);
		int k;
		cin >> k;
		cout << calc[x][k] << "\n";
	}

	return 0;
}
