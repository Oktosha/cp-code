#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = s + 'b';
    for (int i = 0; i < s.size() - 1; ++i) {
        cout << ((int)(s[i] != s[i + 1])) << " ";
    }
    return 0;
}
