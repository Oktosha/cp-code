#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i > 0; --i) {
        a[i] -= a[i - 1];
    }
    /*
    for (int i = 0; i < n; ++i) {
        cerr << a[i] << " ";
    }
    cerr << endl;
    */
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        bool is_possible = true;
        for (int j = 0; j < i; ++j) {
            for (int k = j + i; k < n; k += i) {
                is_possible = is_possible && (a[j] == a[k]);
            }
        }
        if (is_possible) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
