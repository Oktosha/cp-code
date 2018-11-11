#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	string s, t;
	cin >> s;
	cin >> t;
	if (s.find('*') == string::npos) {
		// cerr << "* is absent" << endl;
		if (s == t) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}

	auto pref = s.substr(0, s.find('*'));
	auto suf = s.substr(s.find('*') + 1);

	// cerr << "pref: " << pref << endl;
	// cerr << "suff: " << suf << endl;

	if (pref.size() + suf.size() > t.size()) {
		// cerr << "s is too long" << endl;
		cout << "NO" << endl;
		return 0;
	}

	auto pref_t = t.substr(0, pref.size());
	auto suf_t = t.substr(t.size() - suf.size());

	if (pref == pref_t && suf == suf_t) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
