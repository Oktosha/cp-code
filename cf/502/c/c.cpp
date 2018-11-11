#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		a[i] = i + 1;
	}
	int k = sqrt(N);
	if (k * k < N)
		++k;
	
	for (int i = 0; i * k < N; ++i) {
		reverse(a.begin() + (i * k), a.begin() + min((i + 1) * k, N));
	}
	for (int i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
