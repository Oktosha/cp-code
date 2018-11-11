#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int ans = N;
	for (int i = 1; i <= s.size() / 2; ++i) {
		// cerr << s.substr(0, i) << " " << s.substr(0, i) << endl;
		if (s.substr(0, i) == s.substr(i, i)) {
			ans = N - i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
