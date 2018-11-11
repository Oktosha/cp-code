#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

const string INFINITY = "INFINITY IS NOT A LIMIT!111111111111111111111111111111 AZAZAZA";
const int MAX_OPERATIONS = 16;
const int N_MASKS = 256;

const int iF = 0;
const int iT = 1;
const int iE = 2;

vector<vector<string>> ans(N_MASKS, vector<string>(3, INFINITY));
void relax(int mask, int i, string s) {
	if ((s.size() < ans[mask][i].size()) 
		|| (s.size() == ans[mask][i].size() && s < ans[mask][i]))
		ans[mask][i] = s;

}

int main() {
	ios_base::sync_with_stdio(false);

	ans[0b00001111][iE] = ans[0b00001111][iT] = ans[0b00001111][iF] = "x";
	ans[0b00110011][iE] = ans[0b00110011][iT] = ans[0b00110011][iF] = "y";
	ans[0b01010101][iE] = ans[0b01010101][iT] = ans[0b01010101][iF] = "z";

	for (int op = 0; op < MAX_OPERATIONS; ++op) {
		for (int mask = 0; mask < N_MASKS; ++mask) {
			for (int i = 1; i < 3; ++i) {
				relax(mask, iF, "(" + ans[mask][i] + ")");
			}
			for (int i = 1; i < 3; ++i) {
				for (int j = 0; j < i; ++j) {
					relax(mask, i, ans[mask][j]);
				}
			}
		}

		for (int mask = 0; mask < N_MASKS; ++mask) {
			string not_formula = "!" + ans[mask][iF];
			int res_mask = (~mask) & (N_MASKS - 1);
			relax(res_mask, iF, not_formula);
		}

		for (int m1 = 0; m1 < N_MASKS; ++m1) {
			for (int m2 = 0; m2 < N_MASKS; ++m2) {
				string and_formula = ans[m1][iT] + "&" + ans[m2][iF];
				int and_res_mask = m1 & m2;
				relax(and_res_mask, iT, and_formula);
				string or_formula = ans[m1][iE] + "|" + ans[m2][iT];
				int or_res_mask = m1 | m2;
				relax(or_res_mask, iE, or_formula);
			}
		}
	}
	/*
	for (int mask = 0; mask < N_MASKS; ++mask) {
		cerr << bitset<8>(mask) << " " << ans[mask][iE] << endl;
	}
	*/

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		bitset<8> mask;
		cin >> mask;
		cout << ans[mask.to_ulong()][iE] << "\n";
	}
	return 0;
}