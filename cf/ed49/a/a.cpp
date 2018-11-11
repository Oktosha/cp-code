#include <bits/stdc++.h>

using namespace std;

string move(char ch) {
	if (ch == 'a')
		return "b";
	if (ch == 'z')
		return "y";
	string ans = "$$";
	ans[0] = ch + 1;
	ans[1] = ch - 1;
	return ans;
}

bool have_common_symbols(string a, string b) {
	for (auto ch : a) {
		if (b.find(ch) != string::npos)
			return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int test = 0; test < N; ++test) {
		int len;
		cin >> len;
		string s;
		cin >> s;
		bool can_be_palyndrome = true;
		for (int i = 0; i < s.size() / 2; ++i) {
			char c = s[i];
			char d = s[s.size() - 1 - i];
			string sc = move(c);
			string sd = move(d);
			can_be_palyndrome = can_be_palyndrome && have_common_symbols(sc, sd);
		}
		cout << (can_be_palyndrome ? "YES" : "NO") << "\n";
	}
	return 0;
}
