#include <iostream>
#include <vector>

using namespace std;

bool is_unique(int i, const vector<string> &pins) {
  // cerr << "Testing " << i << " for unique" << "\n";
  /*
  for (int j = 0; j < pins.size(); ++j) {
    cerr << pins[j] << "\n";
  }
  */
  for (int j = 0; j < pins.size(); ++j) {
    if (j != i) {
      if (pins[j] == pins[i]) {
        return false;
      }
    }
  }
  return true;
}

char get_unique_first_digit(const vector<string> &pins) {
  vector<bool> ch_is_present(10, false);
  for (int i = 0; i < pins.size(); ++i) {
    ch_is_present[pins[i][0] - '0'] = true;
  }
  for (int i = 0; i < pins.size(); ++i) {
    if (!ch_is_present[i]) {
      return '0' + i;
    }
  }
  return 'X';
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    vector<string> pins(N);
    for (int i = 0; i < N; ++i) {
      cin >> pins[i];
    }
    // cerr << "input complete" << endl;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (!is_unique(i, pins)) {
        ++ans;
        pins[i][0] = get_unique_first_digit(pins);
      }
    }
    cout << ans << "\n";
    for (auto s : pins) {
      cout << s << "\n";
    }
  }
  return 0;
}