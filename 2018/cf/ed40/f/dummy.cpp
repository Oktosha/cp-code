#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

long long MODULO = 1000000007;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> dp(m, vector<long long>(3, 0));
	vector<vector<bool>> track(m, vector<bool>(3, true));
	for (int i = 0; i < n; ++i) {
		int a, l, r;
		cin >> a >> l >> r;
		--a;
		--l;
		--r;
		for (int j = l; j <= r; ++j) {
			track[j][a] = false;
		}
	}

	dp[0][1] = 1;
	for (int i = 1; i < m; ++i) {
		dp[i][0] = track[i][0] ? (dp[i - 1][0] + dp[i - 1][1]) % MODULO : 0;
		dp[i][1] = track[i][1] ? (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MODULO : 0;
		dp[i][2] = track[i][2] ? ( dp[i - 1][1] + dp[i - 1][2]) % MODULO : 0;
	}
	
	for (int a = 0; a < 3; ++a) {
		for (int i = 0; i < m; ++i) {
			cout << dp[i][a] << " ";
		}
		cout << endl;
	}

	cout << dp[m - 1][1] << endl;
	return 0;
}