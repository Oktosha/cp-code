#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ev {
  long long time;
  long long type;
  bool operator < (const Ev &e) const {
    return time < e.time;
  }
};

struct AccumEvent {
  long long time;
  long long n_easy;
  long long n_hard;
};

long long greedy_solve(long long T, long long mandatory_easy, long long mandatory_hard, long long total_easy, long long total_hard, long long a, long long b) {
  if (mandatory_hard * b +  mandatory_easy * a > T) {
    return 0;
  }
  long long ans = mandatory_easy + mandatory_hard;
  long long free_time = T - (mandatory_hard * b +  mandatory_easy * a);
  long long n_free_easy = min(free_time / a, total_easy - mandatory_easy);
  ans += n_free_easy;
  free_time -= n_free_easy * a;
  long long n_free_hard = min(free_time / b, total_hard - mandatory_hard);
  ans += n_free_hard;
  return ans;
}
int main() {
  int N_TESTS;
  cin >> N_TESTS;
  for (int test = 0; test < N_TESTS; ++test) {
    long long n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<int> types(n);
    long long total_easy = 0;
    long long total_hard = 0;
    for (auto &x : types) {
      cin >> x;
      if (x == 0) {
        ++total_easy;
      } else {
        ++total_hard;
      }
    }
    vector<Ev> events(n);
    for (int i = 0; i < n; ++i) {
      cin >> events[i].time;
      events[i].type = types[i];
    }
    sort(events.begin(), events.end());

    vector<AccumEvent> a_events;
    a_events.push_back({0, 0, 0});
    for (auto e : events) {
      if (e.time != a_events.back().time) {
        a_events.push_back({e.time, 0, 0});
      }
      if (e.type == 0) {
        ++a_events.back().n_easy;
      } else {
        ++a_events.back().n_hard;
      }
    }

    long long ans = 0;
    long long mandatory_easy = 0;
    long long mandatory_hard = 0;
    for (auto e : a_events) {
      long long prev_time = e.time - 1;
      if (prev_time > 0) {
        ans = max(ans, greedy_solve(prev_time, mandatory_easy, mandatory_hard, total_easy, total_hard,a,b));
      }
      mandatory_easy += e.n_easy;
      mandatory_hard += e.n_hard;
    }
    ans = max(ans, greedy_solve(T, mandatory_easy, mandatory_hard, total_easy, total_hard,a,b));
    cout << ans << "\n";
  }

  return 0;
}
