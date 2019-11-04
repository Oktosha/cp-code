#include <iostream>
#include <set>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    string s;
    cin >> s;
    set<char> good;
    int n_serial = 0;
    s = "$" + s + "$";
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[i - 1]) {
        ++n_serial;
      } else {
        if (n_serial % 2 == 1) {
          good.insert(s[i - 1]);
        }
        n_serial = 1;
      }
    }
    for (auto ch : good) {
      cout << ch;
    }
    cout << endl;
  }
  return 0;
}
