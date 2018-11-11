#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

long long MODULO = 1000000007;

template<size_t N, size_t M, size_t K>
array<array<long long, K>, N> multiply(array<array<long long, M>, N> a, array<array<long long, K>, M> b) {
	array<array<long long, K>, N> ans;
	for (int n = 0; n < N; ++n) {
		for (int k = 0; k < K; ++k) {
			ans[n][k] = 0;
			for (int m = 0; m < M; ++m) {
				ans[n][k] = (ans[n][k] + a[n][m] * b[m][k]) % MODULO;
			}
		}
	}
	return ans;
}

array<array<long long, 3>, 3> E = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};

struct Ev {
	// we store [...)
	// but in the input [...]
	array<int, 3> t; // -1 close, +1 open
	long long x;
	Ev (array<int, 3> t, long long x): t(t), x(x) {}
	bool operator < (Ev e) const {
		return x < e.x || (x == e.x && t > e.t);
	}
};

template<size_t M>
array<array<long long, M>, M> pow(array<array<long long, M>, M> A, long long x) {
	if (x == 0) {
		return E;
	}
	if (x == 1) {
		return A;
	}
	auto As = pow(A, x / 2);
	return multiply(multiply(As, As), pow(A, x % 2));
}

template <class T1, class T2, size_t M>
array<T1, M> operator + (array<T1, M> a, array<T2, M> b) {
	array<T1, M> ans;
	for (int i = 0; i < M; ++i) {
		ans[i] = a[i] + b[i];
	}
	return ans;
}

array<array<long long, 3>, 3> FULL_STEP = {{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}};

array<array<long long, 3>, 3> step_matrix(array<int, 3> raw) {
	auto ans = FULL_STEP;
	for (int i = 0; i < 3; ++i) {
		if (raw[i] > 0) {
			for (int j = 0; j < 3; ++j) {
				ans[i][j] = 0;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	long long m;
	cin >> m;
	
	vector<Ev> e;
	for (int i = 0; i < n; ++i) {
		int a;
		long long l, r;
		cin >> a >> l >> r;
		--a;
		++r;
		array<int, 3> tl = {0, 0, 0};
		tl[a] = 1;
		array<int, 3> tr = {0, 0, 0};
		tr[a] = -1;
		e.emplace_back(tl, l);
		e.emplace_back(tr, r);
	}
	sort(e.begin(), e.end());

	/*
	cout << "Raw events" << endl;
	for (int i = 0; i < e.size(); ++i) {
		printf("%2lld ", e[i].x);
	}
	cout << endl;
	for (int a = 0; a < 3; ++a) {
		for (int i = 0; i < e.size(); ++i) {
			printf("%2d ", e[i].t[a]);
		}
		cout << endl;
	}
	cout << endl;
	*/
	

	for (int i = 1; i < e.size(); ++i) {
		e[i].t = e[i - 1].t + e[i].t;
	}
	if (e[0].x > 2) {
		e.insert(e.begin(), Ev(array<int, 3>({0, 0, 0}), 2));		
	}
	e.emplace_back(array<int, 3>({0, 0, 0}), m + 1);

	/*
	cout << "Balances" << endl;
	for (int i = 0; i < e.size(); ++i) {
		printf("%2lld ", e[i].x);
	}
	cout << endl;
	for (int a = 0; a < 3; ++a) {
		for (int i = 0; i < e.size(); ++i) {
			printf("%2d ", e[i].t[a]);
		}
		cout << endl;
	}
	cout << endl;
	*/
	


	vector<Ev> ue;
	for (int i = 0; i < e.size(); ++i) {
		if (i == e.size() - 1 || e[i].x < e[i + 1].x) {
			ue.push_back(e[i]);
		}
	}
	
	/*
	cout << "Unique events" << endl;
	for (int i = 0; i < ue.size(); ++i) {
		printf("%2lld ", ue[i].x);
	}
	cout << endl;
	for (int a = 0; a < 3; ++a) {
		for (int i = 0; i < ue.size(); ++i) {
			printf("%2d ", ue[i].t[a]);
		}
		cout << endl;
	}
	cout << endl;
	*/
	
	


	array<array<long long, 1>, 3> ans = {{{0}, {1}, {0}}};
	for (int i = 0; i < ue.size() - 1; ++i) {
		// cout << i << ". step from " << ue[i].x << " to " << ue[i + 1].x - 1 << endl;
		auto step = step_matrix(ue[i].t);
		long long n_steps = ue[i + 1].x - ue[i].x;
		// cerr << "n steps " << n_steps << endl;
		
		/*
		cerr << "single step" << endl;
		for (int ii = 0; ii < 3; ++ii) {
			for (int ij = 0; ij < 3; ++ij) {
				cout << step[ii][ij] << " ";
			}
			cout << endl;
		}
		*/

		auto powed = pow(step, n_steps);
		
		/*
		cerr << "powed step" << endl;
		for (int ii = 0; ii < 3; ++ii) {
			for (int ij = 0; ij < 3; ++ij) {
				cout << powed[ii][ij] << " ";
			}
			cout << endl;
		}
		*/
		
		ans = multiply(powed, ans);

		/*	
		cerr << "ans";
		for (int i = 0; i < 3; ++i) {
			cerr << " " << ans[i][0];
		} 
		cerr << endl;
		*/
		
	}
	cout << ans[1][0] << endl;
	return 0;
}
