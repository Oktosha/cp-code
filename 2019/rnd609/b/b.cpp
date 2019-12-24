#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  long long m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &x : a)  {
    cin >> x;
  }
  vector<long long> b(n);
  for (auto &x : b)  {
    cin >> x;
  }
  sort(b.begin(), b.end());

  long long min_shift = m;
  for (int i = 0; i < n; ++i) {
    long long shift = (m + b[i] - a[0]) % m;
    auto shifted_a = a;
    for (auto &x : shifted_a) {
      x = (x + shift) % m;
    }
    sort(shifted_a.begin(), shifted_a.end());
    if (shifted_a == b) {
      min_shift = min(shift, min_shift);
    }
  }
  cout << min_shift << "\n";
  return 0;
}