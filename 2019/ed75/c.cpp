#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    string s;
    cin >> s;
    vector<int> even;
    vector<int> odd;
    for (char ch : s) {
      if ((ch - '0') % 2 == 0) {
        even.push_back(ch - '0');
      } else {
        odd.push_back(ch - '0');
      }
    }
    even.push_back(100500);
    odd.push_back(100500);
    vector<char> ans;
    int pos_even = 0;
    int pos_odd = 0;
    while(even[pos_even] < 100500 || odd[pos_odd] < 100500) {
      if (even[pos_even] < odd[pos_odd]) {
        ans.push_back(even[pos_even++]);
      } else {
        ans.push_back(odd[pos_odd++]);
      }
    }
    for (int e : ans) {
      cout << e;
    }
    cout << endl;
  }
  return 0;
}