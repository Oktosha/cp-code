#include <iostream>
#include <vector>

using namespace std;

const int MAX_TYPE = 105;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> c(MAX_TYPE, 0);
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		++c[a];
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int fed = 0;
		for (int j = 0; j < MAX_TYPE; ++j) {
			fed += c[j] / i;
		}
		if (fed >= n) {
			ans = i;
		}
	}

	cout << ans << endl;

	return 0;
}
