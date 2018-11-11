#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> a = {100, 20, 10, 5, 1};
	long long ans = 0;
	for (auto c : a) {
		ans += n / c;
		n %= c;
	}
	cout << ans << endl;
	return 0;
}