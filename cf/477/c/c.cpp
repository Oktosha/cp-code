#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long oldest_bit(long long x) {
	int ans = 0;
	while(x > 0) {
		x /= 2;
		++ans;
	}
	return ans;
}

void add_to_ans(vector<long long> &ans, vector<long long> &a, long long bit_n) {
	
	/*
	cerr << "bit_n: " << bit_n << " number is " << (1LL << bit_n) << endl;

	cerr << "Adding a[" << bit_n << "]" << endl;
	for (int i = 0; i < a.size(); ++i) {
		cerr << a[i] << " ";
	}
	cerr << endl;
	cerr << "To cur ans " << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cerr << ans[i] << " ";
	}
	cerr << endl;
	*/
	
	vector<long long> new_ans;
	if (a.empty()) {
	//	cerr << "a is empty, nothing to do" << endl;
		return;
	}

	int i = 0;
	bool added_1_from_old_ans;
	do {
		added_1_from_old_ans = false;
		new_ans.push_back(a.back());
		a.pop_back();
		while ((i < ans.size()) && ((ans[i] & (1LL << bit_n)) == 0)) {
			new_ans.push_back(ans[i++]);
		}
		if (i < ans.size()) {
			new_ans.push_back(ans[i++]);
			added_1_from_old_ans = true;
		}
	} while (!a.empty() && added_1_from_old_ans);
	for (int j = i; j < ans.size(); ++j) {
		new_ans.push_back(ans[j]);
	}
	ans = new_ans;
	// cerr << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<long long>> a(62);
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		a[oldest_bit(x)].push_back(x);
	}
	vector<long long> ans;
	for (int i = 61; i > 0; --i) {
		add_to_ans(ans, a[i], i - 1);
		if (!a[i].empty()) {
			cout << "No" << "\n";
			return 0;
		}
	}

	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}