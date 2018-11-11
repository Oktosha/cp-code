#include <iostream>

using namespace std;

enum RawOperation {
	AND,
	OR,
	XOR,
	NOT,
	IN
};

enum UpOperation {
	UP_ONE,
	UP_ZERO,
	UP_ID,
	UP_NOT
};

struct Node {
	RawOperation op;
	int val;
	int l;
	int r;
};

void dfs(int v, vector<Node> &node) {
	if (node[v].op == IN) {
		return;
	}
	if (node[v].op == AND) {
		dfs(node[v].l, node);
		dfs(node[v].r, node);
		node[v].val = node[node[v].l].val && node[node[v].r].val;
		return;
	}
	if (node[v].op == OR) {
		dfs(node[v].l, node);
		dfs(node[v].r, node);
		node[v].val = node[node[v].l].val || node[node[v].r].val;
		return;
	}
	if (node[v].op == XOR) {
		dfs(node[v].l, node);
		dfs(node[v].r, node);
		node[v].val = node[node[v].l].val ^ node[node[v].r].val;
		return;
	}
	if (node[v].op == NOT) {
		dfs(node[v].l, node);
		node[v].val = !node[node[v].l].val;
		return;
	}
}

void dfs2(int v, vector<Node> &node, UpOperation up, vector<bool> &ans) {
	if (node[v].op == IN) {
		if (up == UP_ONE) {
			ans[v] = 1;
			return;
		}
		if (up == UP_ZERO) {
			ans[v] = 0;
			return;
		}
		if (up == UP_ID) {
			ans[v] = !node[v].val;
			return;
		}
		if (up == UP_NOT) {
			ans[v] = node[v].val;
			return;
		}
	}
	if (node[v].op == AND) {
		dfs(node[v].l, node, node[node[v].r].val ? IN);
		dfs(node[v].r, node);
		node[v].val = node[node[v].l].val && node[node[v].r].val;
		return;
	}
	if (node[v].op == OR) {
		dfs(node[v].l, node);
		dfs(node[v].r, node);
		node[v].val = node[node[v].l].val || node[node[v].r].val;
		return;
	}
	if (node[v].op == XOR) {
		dfs(node[v].l, node);
		dfs(node[v].r, node);
		node[v].val = node[node[v].l].val ^ node[node[v].r].val;
		return;
	}
	if (node[v].op == NOT) {
		dfs(node[v].l, node);
		node[v].val = !node[node[v].l].val;
		return;
	}
}

int main() {
	int N;
	cin >> N;
	vector<Node> node(N + 1);
	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;
		if (s == "IN") {
			node[i].op = IN;
			cin >> node[i].val;
		}
		if (s == "AND") {
			node[i].op = AND;
			cin >> node[i].l >> node[i].r;
		}
		if (s == "OR") {
			node[i].op = OR;
			cin >> node[i].l >> node[i].r;
		}
		if (s == "XOR") {
			node[i].op = XOR;
			cin >> node[i].l >> node[i].r;
		}
		if (s == "NOT") {
			node[i].op = NOT;
			cin >> node[i].l;
		}
	}
	dfs(1, node);
	return 0;
}
