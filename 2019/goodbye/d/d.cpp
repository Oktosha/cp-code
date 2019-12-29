#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  for (int i = 1; i <= k + 1; ++i) {
    cout << "?";
    for (int j = 1; j <= k + 1; ++j) {
      if (j != i) {
        cout << " " << j;
      }
    }
    cout << endl;
    cout.flush();
    int pos, value;
    cin >> pos >> value;
    ++cnt[value];
  }
  /*
  for (auto [value, count] : cnt) {
    cerr << value << " " << count << "\n";
  }
  */
  cout << "! " << cnt.rbegin()->second << endl;
  cout.flush();
  return 0;
}
