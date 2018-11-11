#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<char> vowels = {'a', 'o', 'u', 'i', 'e'};
	string s;
	cin >> s;
	bool is_berland = true;
	for (int i = 0; i < s.size(); ++i) {
		if (vowels.count(s[i]) == 0 && s[i] != 'n') {
			if ((i == s.size() - 1) || (vowels.count(s[i + 1]) == 0)) {
				is_berland = false;
			}
		}
	}
	cout << (is_berland ? "YES" : "NO") << endl;
	return 0;
}
