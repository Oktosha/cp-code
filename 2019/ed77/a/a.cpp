#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    long long c, sum;
    cin >> c >> sum;
    long long n_sections = sum / c;
    long long n_extra_sections = sum % c;
    int normal_cost = n_sections * n_sections * (c - n_extra_sections);
    int extra_cost = (n_sections + 1) * (n_sections + 1) * n_extra_sections;
    cout << (normal_cost + extra_cost) << "\n";
  }
  return 0;
}
