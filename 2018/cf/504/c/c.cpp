#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	string ans;
	int cnt = 0;
	for (char ch : s) {
		ans.push_back(ch);
		while ((ans.size() >= 2)
			   && (ans.substr(ans.size() - 2) == "()")
			   && (cnt < (N - K))) {
			ans.pop_back();
			ans.pop_back();
			cnt += 2;
		}
	}

	cout << ans << endl;
	return 0;
}
