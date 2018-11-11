#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Vertex {
	int n;
	int d; //degree
	bool operator < (Vertex v) const {
		return d > v.d;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Vertex> v(n);
	for (int i = 0; i < n; ++i) {
		v[i].n = i + 1;
		v[i].d = 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		++v[a - 1].d;
		++v[b - 1].d;
	}

	sort(v.begin(), v.end());

	if (v[1].d > 2) {
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	int n_paths = count_if(v.begin(), v.end(), [](Vertex v) { return v.d == 1; });
	if (v[0].d == 1)
		--n_paths;
	cout << n_paths << endl;
	for (int i = v.size() - 1; (i > 0) && (v[i].d == 1); --i) {
		cout << v[0].n << " " << v[i].n << endl;
	}

	return 0;
}