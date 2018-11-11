#include <iostream>
#include <vector>

using namespace std;

const int MAX_A = 100006;

int main() {
	ios_base::sync_with_stdio(false);
	vector<int> a(MAX_A, 0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++a[x];
	}
	bool conan_wins = false;
	for (int i = 0; i < MAX_A; ++i) {
		conan_wins = conan_wins || (a[i] % 2 == 1);
	}
	cout << (conan_wins ? "Conan" : "Agasa") << endl;
	return 0;
}
