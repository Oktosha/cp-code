#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 705;

// dp[l][r][0] <- можно ли собрать бинарное дерево 
// + из чисел на отрезке с l по r включительно

// dp[l][r][1] <- можно ли собрать бинарное дерево 
// + из чисел на отрезке c l - 1 по r включительно
// + чтоб число в l - 1 было корнем


// dp[l][r][2] <- можно ли собрать бинарное дерево 
// + из чисел на отрезке c l по r + 1 включительно
// + чтоб число в r + 1 было корнем

bool dp[MAX_N][MAX_N][3] = {0};
bool gcd_cache[MAX_N][MAX_N] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> a(N + 2, 0);
	for (int i = 1; i <= N; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i <= N + 1; ++i) {
		for (int j = 0; j <= N + 1; ++j) {
			gcd_cache[i][j] = gcd(a[i], a[j]) > 1;
		}
	}

	for (int pos = 0; pos <= N + 1; ++pos) {
		dp[pos][pos][0] = true;
		dp[pos][pos][1] = (pos > 0) && gcd_cache[pos][pos - 1];
		dp[pos][pos][2] = (pos < N + 1) && gcd_cache[pos][pos + 1];
	}

	for (int l = 0; l <= N + 1; ++l) {
		for (int r = 0; r < l; ++r) {
			for (int i = 0; i < 3; ++i) {
				dp[l][r][i] = true;
			}
		}
	}

	for (int len = 2; len <= N; ++len) {
		for (int l = 1; l <= N - len + 1; ++l) {
			int r = l + len - 1;
			for (int root = l; root <= r; ++root) {
				bool can_root = dp[l][root - 1][2] && dp[root + 1][r][1];
				dp[l][r][0] |= can_root;
				dp[l][r][1] |= gcd_cache[root][l - 1] && can_root;
				dp[l][r][2] |= gcd_cache[root][r + 1] && can_root;
			}
		}
	}

	cout << (dp[1][N][0] ? "Yes" : "No") << endl;

	return 0;
}
