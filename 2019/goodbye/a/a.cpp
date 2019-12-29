#include <iostream>

using namespace std;

int main() {
  int N_TESTS;
  cin >> N_TESTS;
  for (int test = 0; test < N_TESTS; ++test) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int max1 = 0;
    for (int i = 0; i < k1; ++i) {
      int x;
      cin >> x;
      max1 = max(max1, x);
    }
    int max2 = 0;
    for (int i = 0; i < k2; ++i) {
      int x;
      cin >> x;
      max2 = max(max2, x);
    }
    cout << (max1 > max2 ? "YES" : "NO") << "\n";

  }
  return 0;
}