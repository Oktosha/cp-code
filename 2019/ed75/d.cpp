#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SalaryBound {
  long long l;
  long long r;
};

bool is_possible(long long x, long long s, vector<SalaryBound> &a) {
  vector<SalaryBound> r_ge_x;
  vector<SalaryBound> less_than_median;
  for (const auto &e : a) {
    if (e.r >= x) {
      r_ge_x.push_back(e);
    } else {
      less_than_median.push_back(e);
    }
  }
  if (less_than_median.size() > a.size() / 2) {
    return false;
  }

  sort(r_ge_x.begin(), r_ge_x.end(),
       [](SalaryBound x, SalaryBound y) {return x.l < y.l; });

  int n_elem = a.size() / 2 - less_than_median.size();

  long long money_to_pay = 0;
  for (const auto &e : less_than_median) {
    money_to_pay += e.l;
  }

  for (int i = 0; i < n_elem; ++i) {
    money_to_pay += r_ge_x[i].l;
  }

  for (int i = n_elem; i < r_ge_x.size(); ++i) {
    money_to_pay += max(x, r_ge_x[i].l);
  }

  return money_to_pay <= s;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n;
    long long s;
    cin >> n >> s;
    vector<SalaryBound> a(n);
    for (auto &e : a) {
      cin >> e.l >> e.r;
    }

    long long lans = 0;
    long long rans = s + 1;
    while(rans - lans > 1) {
      long long x = (rans + lans) / 2;
      if (is_possible(x, s, a)) {
        lans = x;
      } else {
        rans = x;
      }
    }
    cout << lans << "\n";
  }
  return 0;
}