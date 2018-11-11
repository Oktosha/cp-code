#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	vector<int> cnt(26, 0);
	for (int i = 0; i < N; ++i) {
		char ch;
		cin >> ch;
		++cnt[ch - 'a'];
	}
	if (*max_element(cnt.begin(), cnt.end()) >= 2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
