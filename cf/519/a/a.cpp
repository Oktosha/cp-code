#include <bits/stdc++.h>

using namespace std;

bool wins(const vector<int> &a, int k) {
    int op = 0;
    int me = 0;
    for (auto x : a) {
        op += x;
        me += k - x;
    }
    if (me > op) {
        return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k = *max_element(a.begin(), a.end());
    while(!wins(a, k)) {
        ++k;
    }
    cout << k << endl;
    return 0;
}
