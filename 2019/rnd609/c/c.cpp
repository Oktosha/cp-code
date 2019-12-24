#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string x;
  cin >> x;
  string y1 = x;
  for (int i = 0; i + k < y1.size(); ++i) {
    y1[i + k] = y1[i];
  }
  if (y1 >= x) {
    cout <<  y1.size() << "\n";
    cout << y1 << "\n";
    return 0;
  }
  string y2 = x;
  int pos = k - 1;
  while(y2[pos] == '9') {
    y2[pos] = '0';
    --pos;
  }
  ++y2[pos];
  for (int i = 0; i + k < y1.size(); ++i) {
    y2[i + k] = y2[i];
  }
  cout << y2.size() << "\n";
  cout <<  y2 << "\n";
  return 0;
}