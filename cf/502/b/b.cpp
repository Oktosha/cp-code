#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;
	string a, b;
	cin >> a >> b;
	long long one_all = 0;
	long long zero_all = 0;
	long long one_meaning = 0;
	long long zero_meaning = 0; 
	for (int i = 0; i < N; ++i) {
		if (a[i] == '1') {
			++one_all;
		}
		if (a[i] == '1' && b[i] == '0') {
			++one_meaning;
		}
		if (a[i] == '0') {
			++zero_all;
		}
		if (a[i] == '0' && b[i] == '0') {
			++zero_meaning;
		}
	}

	long long ans = 0;
	ans += one_meaning * zero_all;
	ans += zero_meaning * one_all;
	ans -= one_meaning * zero_meaning;
	cout << ans << endl;
	return 0;
}
