#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n;
    cin >> n;
    int n_odd = 0;
    int n_ones = 0;
    int n_zeros = 0;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      n_odd += s.length() % 2;
      for (char ch : s) {
        if (ch == '0') {
          n_zeros++;
        } else {
          n_ones++;
        }
      }
    }
    if (n_odd > 0) {
      cout << n << endl;
    } else {
      cout << n - (n_ones % 2) << endl;
    }
  }
  return 0;
}