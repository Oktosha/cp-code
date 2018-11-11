#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int max_len = s.size();
	string t = s + s + s.back();
	int cur = 1;
	int ans = 0;
	for (int i = 1; i < t.size(); ++i) {
		if (t[i] != t[i - 1]) {
			++cur;
		} else {
			ans = max(cur, ans);
			cur = 1;
		}
	}
	cout << min(max_len, ans) << "\n";
	return 0;
}
