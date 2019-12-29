#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N_TESTS;
  cin >> N_TESTS;
  for (int test = 0; test < N_TESTS; ++test) {
    int N;
    cin >> N;
    long long my_sum = 0;
    long long my_xor = 0;
    for (int i = 0; i < N; ++i) {
      long long x;
      cin >> x;
      my_sum += x;
      my_xor ^= x;
    }
    long long S = my_sum + my_xor;
    cout << 2 << "\n";
    cout << my_xor << " " << S << "\n";
  }
}