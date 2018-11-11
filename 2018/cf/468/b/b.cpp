#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	int guessed = 0;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		vector<int> pos;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ch) {
				pos.push_back(i);
			}
		}
		int best_guess = 0;
		for (int d = 1; d < s.size(); ++d) {
			vector<int> char_count(26, 0);
			for (int i = 0; i < pos.size(); ++i) {
				++char_count[s[(pos[i] + d) % s.size()] - 'a'];
			}
			int cur_guess = 0;
			for (int i = 0; i < char_count.size(); ++i) {
				cur_guess += (char_count[i] == 1);
			}
			best_guess = max(best_guess, cur_guess);
		}
		guessed += best_guess;
	}
	cout.precision(10);
	cout << fixed << (((double)(guessed)) / ((double)(s.size()))) << endl;
	return 0;
}
