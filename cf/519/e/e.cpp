#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    vector<long long> sum(n);
    vector<long long> diff(n);
   
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        sum[i] = a + b;
        total_sum += sum[i];
        diff[i] = a - b;
    }

    vector<long long> pos_diff = diff;

    vector<long long> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        ans[i] += total_sum + n * sum[i];
    }

    /*
    cerr << "ans: sum + sum" << endl;
    for (int i = 0; i < n; ++i) {
        cerr << ans[i] << " ";
    }
    cerr << endl;
    */

    sort(diff.begin(), diff.end());
    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + diff[i - 1];
    }

    /*
    cerr << "sorted diff and its pref sums" << endl;
    cerr << "  "; 
    for (int i = 0; i <n; ++i) {
        cerr << diff[i] << " ";
    }
    cerr << endl;
    for (int i = 0; i <=n; ++i) {
        cerr << p[i] << " ";
    }
    cerr << endl;
    */

    for (int i = 0; i < n; ++i) {
        long long l = 0;
        long long r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (diff[m] <= pos_diff[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        // cerr << i << " " << pos_diff[i] << " " << l << endl;
        ans[i] -= (l + 1ll) * pos_diff[i] - (p[l + 1] - p[0]);
        ans[i] -= -(n - (l + 1ll)) * pos_diff[i] + (p[n] - p[l + 1]);
    }

    /*
    cerr << "ans for everyone + eveyone" << endl;
    for (int i = 0; i < n; ++i) {
        cerr << ans[i] << " "; 
    }
    cerr << endl;
    */

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        long long res = sum[u] + sum[v] + min(pos_diff[u] - pos_diff[v], pos_diff[v] - pos_diff[u]);
        ans[u] -= res;
        ans[v] -= res;
    }

    for (int i = 0; i < n; ++i) {
        long long res = sum[i] + sum[i] + pos_diff[i] - pos_diff[i];
        ans[i] -= res;  
    }


    for (int i = 0; i < n; ++i) {
        cout << (ans[i] / 2ll) << " ";
    }
    cout << endl;
    return 0;
}
