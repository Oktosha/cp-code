#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
elephants
0    1    2    3
XX   XX   .X   X.
X.   .X   XX   XX
*/

/*
masks
0 1 2 3
. x . x
. . x x
*/

int e_front[4] = {1, 3, 3, 2}; 
int e_back[4] = {3, 1, 2, 3};

int new_mask(int e, int field) {
	return (e_front[e] | field);
}

bool is_possible(int e, int prev, int next) {
	return ((e_back[e] & prev) == 0) && ((e_front[e] & next) == 0);
}

int main () {
	vector<string> a(2);
	cin >> a[0] >> a[1];
	int n = a[0].size();

	vector<vector<int>> dp(n + 1, vector<int>(4, -1));
	dp[0][3] = 0;

	for (int i = 0; i < n; ++i) {
		int field = ((a[0][i] == 'X') ? 1 : 0) + ((a[1][i] == 'X') ? 2 : 0);
		dp[i + 1][field] = *max_element(dp[i].begin(), dp[i].end());
		for (int mask = 0; mask < 4; ++mask) {
			if (dp[i][mask] != -1) {
				for (int e = 0; e < 4; ++e) {
					if (is_possible(e, mask, field)) {
						int w_e = new_mask(e, field);
						dp[i + 1][w_e] = max(dp[i + 1][w_e], dp[i][mask] + 1);
					}
				}
			}
		}
	}

	/*
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%2d ", dp[i][j]);
		}
		cerr << endl;
	}
	*/

	cout << *max_element(dp[n].begin(), dp[n].end()) << endl;

	return 0;
}
