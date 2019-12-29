#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N_TESTS;
  cin >> N_TESTS;
  for (int test = 0; test < N_TESTS; ++test) {
    int n;
    cin >> n;
    bool is_solution = false;
    int x_prev;
    cin >> x_prev;
    for (int i = 2; i <= n; ++i) {
      int x;
      cin >> x;
      if (abs(x - x_prev) >= 2 && !is_solution) {
        is_solution = true;
        cout << "YES" << "\n";
        cout << i - 1 << " " << i << "\n";
      }
      x_prev = x;
    }
    if (!is_solution) {
      cout << "NO" << "\n";
    }
  }
  return 0;
}
