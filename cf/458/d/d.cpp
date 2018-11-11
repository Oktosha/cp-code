#include <iostream>
#include <cstdio>

using namespace std;

const int DEPTH = 19;
const int TREE_MEMORY_SIZE = 1 << (DEPTH + 1);
const int TREE_SEGMENT_SIZE = 1 << DEPTH;

inline int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
struct SegmentTree {
	int val[TREE_MEMORY_SIZE];
	// l inclusive; r — not
	inline long long get_gcd(int l, int r, int v, int l_v, int r_v) {
		if ((r_v <= l) || (l_v >= r)) {
			return 0;
		}
		if ((l <= l_v) && (r_v <= r)) {
			return val[v];
		}
		int m = (l_v + r_v) / 2;
		long long l_gcd = get_gcd(l, r, v * 2 + 1, l_v, m);
		long long r_gcd = get_gcd(l, r, v * 2 + 2, m, r_v);
		return gcd(l_gcd, r_gcd);
	}
	inline void set(long long value, int pos, int v, int l_v, int r_v) {
		// cerr << "Set at v = " << v << "; l_v = " << l_v << " r_v = " << r_v << endl;
		// cerr << "pos = " << pos << " value = " << value << endl;
		if ((pos < l_v) || (pos >= r_v)) {
			return;
		}
		if ((pos == l_v) && (r_v - l_v == 1)) {
			val[v] = value;
			return;
		}
		int m = (l_v + r_v) / 2;
		set(value, pos, v * 2 + 1, l_v, m);
		set(value, pos, v * 2 + 2, m, r_v);
		long long l_gcd = get_gcd(l_v, m, v * 2 + 1, l_v, m);
		long long r_gcd = get_gcd(m, r_v, v * 2 + 2, m, r_v);
		val[v] = gcd(l_gcd, r_gcd);
	}

	inline int get_r(int l, long long x, int v, int l_v, int r_v) {
		if (val[v] % x == 0) {
			return r_v;
		}

		if (l_v == r_v - 1) {
			return l_v;
		}

		int m = (l_v + r_v) / 2;
		if (l >= m) {
			return get_r(l, x, v * 2 + 2, m, r_v);
		}

		if (get_gcd(l, m, v * 2 + 1, l_v, m) % x == 0) {
			return get_r(m, x, v * 2 + 2, m, r_v);
		}
		return get_r(l, x, v * 2 + 1, l_v, m);
	}
};

SegmentTree seg_tree;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		seg_tree.set(a, i, 0, 0, TREE_SEGMENT_SIZE);
	}

	/*
	cerr << "Gcd on segments" << endl;
	for (int l = 1; l <= n; ++l) {
		for (int r = l; r <= (n + 1); ++r) {
			cerr << l << " " << r << " "
			     << seg_tree.get_gcd(l, r, 0, 0, TREE_SEGMENT_SIZE) << endl;
		}
	}
	cerr << endl;
	*/

	int Q;
	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			if (seg_tree.get_gcd(l, r + 1, 0, 0, TREE_SEGMENT_SIZE) % x == 0) {
				printf("YES\n"); 
			} else {
				/*
				int m_left_l = l;
				int m_left_r = r + 1;
				while(m_left_r - m_left_l > 1) {
					int m = (m_left_l + m_left_r) / 2;
					int cur_gcd = seg_tree.get_gcd(l, m, 0, 0, TREE_SEGMENT_SIZE);
					if (cur_gcd % x == 0) {
						m_left_l = m;
					} else {
						m_left_r = m;
					}
				}
				int m = m_left_l;
				*/
				int m = seg_tree.get_r(l, x, 0, 0, TREE_SEGMENT_SIZE);
				int r_gcd = seg_tree.get_gcd(m + 1, r + 1, 0, 0, TREE_SEGMENT_SIZE);
				if (r_gcd % x == 0) {
					printf("YES\n");
				} else  {
					printf("NO\n");
				}
			}

		}
		if (t == 2) {
			int pos, value;
			scanf("%d %d", &pos, &value);
			seg_tree.set(value, pos, 0, 0, TREE_SEGMENT_SIZE);
		}
	}

	return 0;
}