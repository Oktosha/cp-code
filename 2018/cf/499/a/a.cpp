#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> count(26);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		++count[ch - 'a'];
	}
	int ans = 0;
	int build = 0;
	for (int i = 0; i < 26 && build < k;) {
		if (count[i] > 0) {
			++build;
			ans += i + 1;
			i += 2;
		} else {
			++i;
		}
	}
	if (build < k) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
