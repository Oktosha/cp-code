#include <iostream>

using namespace std;

int main() {
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	if (A < C || B < C || (A + B - C) >= N) {
		cout << -1 << endl;
	} else {
		cout << (N - (A + B - C)) << endl;
	}
	return 0;
}
