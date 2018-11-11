#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Server {
	long long c;
	int n;
	bool operator < (Server s) const {
		return c < s.c;
	}
};

struct Ans {
	bool is_possible;
	int l1;
	int r1;
	int l2;
	int r2;
};


Ans get_ans(int i, long long x1, long long x2, 
			const vector<Server> &a,
			const vector<long long> &b, const vector<long long> &pos) {
	Ans ans;
	long long c = a[i].c;
	long long k1 = (x1 + c - 1) / c;
	long long l2 = i + k1;
	if (l2 >= a.size()) {
		ans.is_possible = false;
		return ans;
	}
	if (b[l2] < x2) {
		ans.is_possible = false;
		return ans;
	}
	ans.is_possible = true;
	ans.l1 = i;
	ans.r1 = i + k1;
	ans.l2 = pos[l2];
	ans.r2 = a.size();
	return ans;
}

void print_ans(Ans ans, bool invert, const vector<Server> &a) {
	if (invert) {
		swap(ans.l1, ans.l2);
		swap(ans.r1, ans.r2);
	}
	cout << "Yes\n";
	cout << (ans.r1 - ans.l1) << " " << (ans.r2 - ans.l2) << "\n";
	for (int i = ans.l1; i < ans.r1; ++i) {
		cout << a[i].n << " ";
	}
	cout << "\n";
	for (int i = ans.l2; i < ans.r2; ++i) {
		cout << a[i].n << " ";
	}
	cout << "\n";
}

int main() {
	int n;
	cin >> n;
	long long x1, x2;
	cin >> x1 >> x2;
	vector<Server> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].c;
		a[i].n = i + 1;
	}
	sort(a.begin(), a.end());
	/*
	cerr << "a.c" << endl; 
	for (int i = 0; i < a.size(); ++i) {
		cerr << a[i].c << " ";
	}
	cerr << endl;
	*/

	vector<long long> b(n, 0);
	vector<long long> pos(n, 0);
	pos[n - 1] = n - 1;
	b[n - 1] = a[n - 1].c;
	for (int i = b.size() - 2; i >= 0; --i) {
		long long len = b.size() - i;
		pos[i] = i;
		b[i] = a[i].c * len;
		if (b[i + 1] > b[i]) {
			b[i] = b[i + 1];
			pos[i] = pos[i + 1];
		}
	}
	/*
	cerr << "b" << endl; 
	for (int i = 0; i < a.size(); ++i) {
		cerr << b[i] << " ";
	}
	cerr << endl;
	cerr << "pos" << endl; 
	for (int i = 0; i < a.size(); ++i) {
		cerr << pos[i] << " ";
	}
	cerr << endl;
	*/
	for (int i = 0; i < a.size(); ++i) {
		auto ans = get_ans(i, x1, x2, a, b, pos);
		if (ans.is_possible) {
			print_ans(ans, false, a);
			return 0;
		}
		ans = get_ans(i, x2, x1, a, b, pos);
		if (ans.is_possible) {
			print_ans(ans, true, a);
			return 0;
		}
	}

	cout << "No\n";

	return 0;
}
