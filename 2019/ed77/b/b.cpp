#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    if (a * 2 < b) {
      cout << "NO" << "\n";
      continue;
    }
    if (a * 2 == b) {
      cout << "YES" << "\n";
      continue;
    }
    if (((a % 2) * 2 + a / 2) > b) {
      cout << "NO" << endl;
      continue;
    }
    long long y_when_2x_plus_y_greater_than_b = 0;
    long long y_when_2x_plus_y_less_or_equal_than_b = a / 2;
    while(y_when_2x_plus_y_less_or_equal_than_b - y_when_2x_plus_y_greater_than_b > 1) {
      long long y_m = (y_when_2x_plus_y_less_or_equal_than_b + y_when_2x_plus_y_greater_than_b) / 2;
      long long x = a - y_m * 2;
      if (2 * x + y_m <= b) {
        y_when_2x_plus_y_less_or_equal_than_b = y_m;
      } else {
        y_when_2x_plus_y_greater_than_b = y_m;
      }
    }
    long long y = y_when_2x_plus_y_less_or_equal_than_b;
    long long x = a - 2 * y;
    if (y + 2 * x == b) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }

  }
  return 0;
}
