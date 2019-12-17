#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;
    int n_even = 0;
    int n_zeros = 0;
    int sum = 0;
    for (auto ch : s) {
      sum += ch - '0';
      n_zeros += ch == '0';
      n_even += ((ch - '0') % 2) == 0;
    }
    if (sum % 3 == 0 && n_zeros >= 1 && n_even >= 2) {
      cout << "red" << "\n";
    } else {
      cout << "cyan" << "\n";
    }
  }
  return 0;
}