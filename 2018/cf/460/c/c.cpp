#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count(string s, int k) {
	// cerr << s << " " << k << endl;
	int ans = 0;
	int cur_empty = 0;
	for (char ch : s) {
		if (ch == '*') {
			ans += ((cur_empty >= k) ? cur_empty - k + 1 : 0);
			cur_empty = 0;
		} else {
			++cur_empty;
		}
	}
	ans += ((cur_empty >= k) ? cur_empty - k + 1 : 0);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	int ans = 0;
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> cl(n);
	for (int i = 0; i < n; ++i) {
		cin >> cl[i];
		ans += count(cl[i], k);
	}
	if (k > 1) {
		for (int i = 0; i < m; ++i) {
			string s(n, '0');
			for (int j = 0; j < n; ++j) {
				s[j] = cl[j][i];
			}
			ans += count(s, k);
		}
	}
	cout << ans << endl;
}