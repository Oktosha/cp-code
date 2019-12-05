#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n_tests;
  cin >> n_tests;
  for (int test = 0; test < n_tests; ++test) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &val : p) {
      cin >> val;
    }

    vector<int> cnt;
    cnt.push_back(1);
    for (int i = 1; i < n; ++i) {
      if (p[i] == p[i - 1]) {
        ++cnt.back();
      } else {
        cnt.push_back(1);
      }
    }

    if (cnt.size() < 4) {
      cout << "0 0 0" << "\n";
      continue;
    }

    if (cnt[0] + cnt[1] + cnt[2] > n / 2) {
      cout << "0 0 0" << "\n";
      continue;
    }

    int gold = cnt[0];

    int silver = 0;
    int i_silver = 1;

    while (silver <= gold && i_silver < cnt.size()) {
      silver += cnt[i_silver];
      ++i_silver;
    }

    if (!(gold < silver) || i_silver == cnt.size()) {
      cout << "0 0 0" << "\n";
      continue;
    }

    int bronze = 0;
    int i_bronze = i_silver;

    while (bronze <= gold && i_bronze < cnt.size()) {
      bronze += cnt[i_bronze];
      ++i_bronze;
    }

    if (i_bronze == cnt.size()) {
      cout << "0 0 0" << "\n";
      continue;
    }

    int extra_bronze = 0;
    while(gold + silver + bronze + extra_bronze <= n / 2) {
      extra_bronze += cnt[i_bronze];
      ++i_bronze;
    }
    extra_bronze -= cnt[i_bronze - 1];

    if (extra_bronze < 0) {
      cout << "0 0 0" << "\n";
      continue;
    }

    cout << gold << " " << silver << " " << bronze + extra_bronze << "\n";
  }
  return 0;
}
