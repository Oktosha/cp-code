#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MAX_X = 100500;
const int SQ_X = 318;
int main() {
	vector<long long> n_div(MAX_X, 2);
	n_div[0] = 0;
	n_div[1] = 1;
	for (int p = 2; p <= SQ_X; ++p) {
		for (int i = 2 * p; i < MAX_X; i += p) {
			++n_div[i];
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		long long ans = n_div[a] * n_div[b] * n_div[c];
		long long gcd_total = gcd(gcd(a, b), c);
		ans -= 5ll * n_div[gcd_total] * (n_div[gcd_total] - 1ll) * (n_div[gcd_total] - 2ll) / 6ll;
		ans -= 2ll * n_div[gcd_total] * (n_div[gcd_total] - 1ll);
		ans -= n_div[gcd(a, b)] * (n_div[gcd(a, b)] - 1ll) * (n_div[c] - n_div[gcd_total]) / 2ll;
		ans -= n_div[gcd(b, c)] * (n_div[gcd(b, c)] - 1ll) * (n_div[a] - n_div[gcd_total]) / 2ll;
		ans -= n_div[gcd(a, c)] * (n_div[gcd(a, c)] - 1ll) * (n_div[b] - n_div[gcd_total]) / 2ll;
		ans -= 2ll * (n_div[gcd(a, c) / gcd_total] - 1) * (n_div[gcd(a, b) / gcd_total] - 1) * n_div[gcd_total];
		ans -= 2ll * (n_div[gcd(a, b) / gcd_total] - 1) * (n_div[gcd(b, c) / gcd_total] - 1) * n_div[gcd_total];
		ans -= 2ll * (n_div[gcd(a, c) / gcd_total] - 1) * (n_div[gcd(b, c) / gcd_total] - 1) * n_div[gcd_total];
		cout << ans << endl;
	}
	return 0;
}