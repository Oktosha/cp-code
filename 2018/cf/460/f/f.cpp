#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

struct Pos {
	vector<int> a;
	vector<int> b;
	size_t h;

	Pos(vector<int> a, vector<int> b): a(a), b(b) {
		long long pow = 1;
		for (int i = 0; i < 5; ++i) {
			h += pow * a[i];
			pow *= 8;
		}
		for (int j = 0; j < 5; ++j) {
			h += pow * a[i];
			pow *= 8;
		}
	}

	vector<Pos> next() const {
		vector<Pos> ans;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (a[i] * b[j] != 0) {
					vector<int> new_b = a;
					--new_b[i];
					++new_b[(a[i] + b[j]) % 5];
					ans.emplace_back(b, new_b);
				}
			}
		}
		return ans;
	}

	bool operator == (Pos p) const {
		return (a == p.a) && (b == p.b);
	}

	int count() {
		if (a[0] == 8 && b[0] == 8) {
			return 0;
		}
		if (a[0] == 8) {
			return 1;
		}
		if (b[0] == 8) {
			return -1;
		}
		return 0;
	}
};

size_t my_hash(Pos p) {
	return p.h;
}

vector<vector<int>> one_pos;
vector<int> cur_pos(5);
vector<Pos> pos;
unordered_map<Pos, int, my_hash> id;
vector<int> cnt;
vector<vector<int>> g_r;
vector<vector<int>> g;
vector<bool> visited;

void gen(int k, int sum_left) {
	if (k == 4) {
		cur_pos[k] = sum_left;
		for (int i = 0; i < 5; ++i) {
			cout << cur_pos[i] << " ";
		}
		cout << endl;
		one_pos.push_back(cur_pos);
		return;
	}
	for (int i = 0; i <= sum_left; ++i) {
		cur_pos[k] = i;
		gen(k + 1, sum_left - i);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	gen(0, 8);
	for (int i = 0; i < one_pos.size(); ++i) {
		for (int j = 0; j < one_pos.size(); ++j) {
			pos.push_back(Pos(one_pos[i], one_pos[j]));
		}
	}
	
	for (int i = 0; i < pos.size(); ++i) {
		id[pos[i]] = i;
	}

	g.resize(pos.size());
	g_r.resize(pos.size());
	cnt.resize(pos.size());
	visited.resize(pos.size(), false);

	queue<Pos> q;
	for (int i = 0; i < pos.size(); ++i) {
		cnt[i] = pos[i].count();
		if (cnt[i] != 0) {
			q.push(i);
			visited[i] = true;
		}
		auto next = pos[i].next();
		for (auto p : next) {
			g_r[id[p]].push_back(i);
		}
	}

	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		for (int i : g_r[cur]) {
			if (!visited[i]) {
				bool all_next_are_wins = true;
				bool any_next_is_loss = false;
				for (int j : g[i]) {
					all_next_are_wins = all_next_are_wins && (cnt[j] == 1);
					any_next_is_loss = any_next_is_loss || (cnt[j] == -1);
				}
				if (any_next_is_loss) {
					cnt[i] = 1;
				}
				if (all_next_are_wins) {
					cnt[i] = -1;
				}
				if (cnt[i] != 0) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}

	int T;
	cin >> T;
	for (int testcase = 0; testcase < T; ++testcase) {
		bool bob_starts;
		cin >> bob_starts;
		vector<int> a(5);
		for (int i = 0; i < 8; ++i) {
			int x;
			cin >> x;
			++a[x];
		}
		vector<int> b(5);
		for (int i = 0; i < 8; ++i) {
			int x;
			cin >> x;
			++b[x];
		}
		string p1_name = "Alice";
		string p2_name = "Bob";
		Pos start = Pos(a, b);
		if (bob_starts) {
			start = Pos(b, a);
			swap(p1_name, p2_name);
		}
		if (cnt[id[start]] == 0) {
			cout << "Deal\n";
		} else {
			cout << ((cnt[id[start]] == 1) ? p1_name : p2_name) << "\n";
		}
	}

	return 0;
}