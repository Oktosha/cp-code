#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	int sum;
	int id;
	bool operator < (Student s) const {
		return sum > s.sum || ((sum == s.sum) && (id < s.id));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Student> s(N);
	for (int i = 0; i < N; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		s[i].id = i;
		s[i].sum = a + b + c + d;
	}
	sort(s.begin(), s.end());
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (s[i].id == 0) {
			ans = i;
		}
	}
	cout << (ans + 1) << endl;
	return 0;
}
