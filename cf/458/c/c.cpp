#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_M = 1005;
const long long MODULO = 1000000007;

int get_n_bits(int x) {
	int ans = 0;
	while (x > 0) {
		ans += x % 2;
		x /= 2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	vector<long long> operations_to_1(MAX_M);
	operations_to_1[0] = -1;
	operations_to_1[1] = 0;
	for (int i = 2; i < MAX_M; ++i) {
		operations_to_1[i] = operations_to_1[get_n_bits(i)] + 1;
	}

	/*
	cerr << "operations_to_1" << endl;
	for (int i = 1; i <= 16; ++i) {
		cerr << i << " " << bitset<5>(i) << " " << operations_to_1[i] << endl;
	}
	*/
	

	vector<vector<long long>> c(MAX_M, vector<long long>(MAX_M, 1));
	for (int n = 2; n < MAX_M; ++n) {
		for (int k = 1; k < n; ++k) {
			c[n][k] = (c[n - 1][k - 1] + c[n - 1][k]) % MODULO;
		}
	}

	/*
	for (int n = 0; n < 5; ++n) {
		for (int k = 0; k <= n; ++k) {
			cerr << c[n][k] << " ";
		}
		cerr << endl;
	}
	*/

	string s;
	cin >> s;
	int K;
	cin >> K;

	vector<long long> n_with_k_bits(MAX_M, 0);
	int n_1_in_pref = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			for (int k = 0; k <= s.size() - i - 1; ++k) {
				n_with_k_bits[k + n_1_in_pref] += c[s.size() - i - 1][k];
				n_with_k_bits[k + n_1_in_pref] %= MODULO;
			}
			++n_1_in_pref;
		}
	}
	++n_with_k_bits[n_1_in_pref];

	--n_with_k_bits[1]; // we don't want to count 1
	--n_with_k_bits[0]; // we don't want to count 0

	/*
	cerr << "n_with_k_bits" << endl;
	for (int k = 0; k < 6; ++k) {
		cerr << k << " " << n_with_k_bits[k] << endl;
	}
	*/

	if (K == 0) {
		cout << 1 << endl;
	} else  {
		long long ans = 0;
		for (int i = 1; i < MAX_M; ++i) {
			if (operations_to_1[i] + 1 == K) {
				ans += n_with_k_bits[i];
				ans %= MODULO;
			}
		} 
		cout << ans << endl;
	}


	return 0;
}
