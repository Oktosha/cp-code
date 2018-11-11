#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	string sr = s;
	reverse(sr.begin(), sr.end());
	if (s != sr) {
		cout << s.size() << endl;
		return 0;
	}
	bool is_one_symbol = true;
	for (int i = 1; i < s.size(); ++i) {
		is_one_symbol = is_one_symbol && (s[i] == s[i - 1]);
	}
	if (is_one_symbol) {
		cout << 0 << endl;
		return 0;
	}
	cout << (s.size() - 1) << endl; 
	return 0;
}