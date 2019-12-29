#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ev {
  int t;
  long long x;
};

bool compare(Ev a, Ev b) {
  return a.x < b.x;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    long long a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) {
      swap(a, b);
    }
    vector<Ev> events;
    events.push_back({1, a});
    events.push_back({-1, b});
    events.push_back({1, c - r});
    events.push_back({-1, c + r});
    sort(events.begin(), events.end(), compare);
    int balance = 0;
    long long intersection = 0;
    for (int i = 0; i < events.size(); ++i) {
      if (balance == 2) {
        intersection += events[i].x - events[i - 1].x;
      }
      balance += events[i].t;
    }
    cout << (b - a - intersection) << "\n";
  }
  return 0;
}