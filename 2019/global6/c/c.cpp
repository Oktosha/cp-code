#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int r, c;
  cin >> r >> c;

  if ((r == 1) && (c == 1)) {
    cout << 0 << endl;
    return 0;
  }

  if (r == 1) {
    for (int i = 0; i < c; ++i) {
      cout << i + 2 << " ";
    }
    cout << "\n";
    return 0;
  }

  if (c == 1) {
    for (int i = 0; i < r; ++i) {
      cout << i + 2 << "\n";
    }
    return 0;
  }

  for (int i = 1; i <= r; ++i) {
    for (int j = r + 1; j <= r + c; ++j) {
      cout << i * j << " ";
    }
    cout << "\n";
  }
  return 0;
}
