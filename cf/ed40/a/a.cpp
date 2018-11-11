#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	char last = 'D';
	int n_changes = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (((last == 'R' && s[i] == 'U')) || ((last == 'U') && (s[i] == 'R'))) {
			last = 'D';
			++n_changes;
		} else {
			last = s[i];
		}
	}
	cout << (N - n_changes) << endl;
	return 0;
}
