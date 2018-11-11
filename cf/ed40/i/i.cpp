#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

 
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

size_t get_min_2_pow(int x) {
	size_t n = 1;
	while (n < x)  n <<= 1;
	n <<= 1;
	return n;
}

vector<vector<cd>> fill_masks(string s) {
	vector<vector<cd>> ans(6, vector<cd>(s.size(), 0));
	for (int i = 0; i < s.size(); ++i) {
		ans[s[i] - 'a'][i] = 1;
	}
	return ans;
}

void dfs(int v, const vector<vector<int>> &g, vector<bool> &used) {
	used[v] = true;
	// cerr << "dfs " << v << endl;
	for (int i = 0; i < 6; ++i) {
		if ((g[v][i] > 0) && (!used[i])) {
			dfs(i, g, used);
		}
	}
}


int main() {
	string s, t;
	cin >> s >> t;
	reverse(t.begin(), t.end());
	auto a = fill_masks(s);
	auto b = fill_masks(t);
	int len = get_min_2_pow(s.size());
	for (int i = 0; i < a.size(); ++i) {
		a[i].resize(len);
		fft(a[i], false);
	}
	for (int i = 0; i < b.size(); ++i) {
		b[i].resize(len);
		fft(b[i], false);
	}

	/*
	cerr << "a bitmasks" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			cerr << a[i][j];
		}
		cerr << endl;
	}

	cerr << "b bitmasks" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < b[i].size(); ++j) {
			cerr << b[i][j];
		}
		cerr << endl;
	}
	*/

	vector<vector<vector<cd>>> product(6, vector<vector<cd>>(6, vector<cd>(len)));
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (i != j) {
				for (int k = 0; k < len; ++k) {
					product[i][j][k] = a[i][k] * b[j][k];
				}
				fft(product[i][j], true);
			}
		}
	}

	for (int i = t.size() - 1; i < s.size(); ++i) {

		vector<bool> used(6, false);
		vector<vector<int>> g(6, vector<int>(6));
		for (int u = 0; u < 6; ++u) {
			for (int v = u + 1; v < 6; ++v) {
				g[v][u] = g[u][v] = ((int)(product[u][v][i].real() + 0.5) > 0) 
				           || ((int)(product[v][u][i].real() + 0.5) > 0) ;
			}
		}
		/*
		cerr << "g" << endl;
		for (int u = 0; u < 6; ++u) {
			for (int v = 0; v < 6; ++v) {
				cerr << g[u][v];
			}
			cerr << endl;
		}
		*/
		int n_components = 0;
		for (int j = 0; j < 6; ++j) {
			/*
			cerr << "used before dfs from " << j << " ";
			for (int k = 0; k < 6; ++k) {
				cerr << used[k];
			}
			cerr << endl;
			*/
			if (!used[j]) {
				++n_components;
				dfs(j, g, used);
			}
		}

		// cerr << "n components " << n_components << endl;
		cout << 6 - n_components << endl;
	}

	return 0;
}
