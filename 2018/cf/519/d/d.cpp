#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<vector<int>> pos(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
    long long ans = 0;
    long long l = 0;
    for (int i = 0; i < n; i += l) {
        l = 0;
        bool is_good = true;
        while (is_good) {
            ++l;
            int cur_n = a[0][i];
            for (int sosed = 0; sosed < m; ++sosed) {
                is_good = is_good 
                          && (pos[sosed][cur_n] + l < n)
                          && (a[sosed][pos[sosed][cur_n] + l] == a[0][i + l]);
            }
        }
        // cerr << i << " " << l << endl;
        ans += l * (l + 1ll) / 2ll;
    }
    cout << ans << "\n";
    return 0;
}
