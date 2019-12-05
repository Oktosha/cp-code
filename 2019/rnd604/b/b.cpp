#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int x) {
  return x > 0 ? x : -x;
}

int main() {
  ios_base::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int A = a;
  int B = b;
  int C = c;
  int D = d;
  if (abs(a + c - (b + d)) > 1) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> ans_head;
  if (a > 0 && (a + c) >= b + d) {
    ans_head.push_back(0);
    --a;
  }
  while(a > 0) {
    ans_head.push_back(1);
    ans_head.push_back(0);
    --a;
    --b;
  }

  /*
  cerr << "Ans head: ";
  for (int e : ans_head) {
    cout << " " << e;
  }
  cout << endl;
*/

  if (b < 0) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> ans_tail;
  if (D > 0 && (B + D) >= A + C) {
    ans_tail.push_back(3);
    --d;
  }
  while(d > 0) {
    ans_tail.push_back(2);
    ans_tail.push_back(3);
    --c;
    --d;
  }
  if (c < 0) {
    cout << "NO" << endl;
    return 0;
  }
  reverse(ans_tail.begin(), ans_tail.end());

/*
  cerr << "Ans tail: ";
  for (int e : ans_tail) {
    cout << " " << e;
  }
  cout << endl;
*/

  vector<int> ans_middle;
  if (c > b) {
    ans_middle.push_back(2);
    --c;
  }
  while(c > 0) {
    ans_middle.push_back(1);
    ans_middle.push_back(2);
    --b;
    --c;
  }
  if (b < 0 || b > 1) {
    cout << "NO" << endl;
    return 0;
  }
  if (b == 1) {
    ans_middle.push_back(1);
    --b;
  }

  /*
  cerr << "Ans middle: ";
  for (int e : ans_middle) {
    cout << " " << e;
  }
  cout << endl;
*/

  if (a != 0 || b != 0 || c != 0 || d != 0) {
    // I guess this shoudn't happen
    cout << "NO" << endl;
    return 0;
  }

  vector<int> ans;
  for (auto e : ans_head) {
    ans.push_back(e);
  }
  for (auto e : ans_middle) {
    ans.push_back(e);
  }
  for (auto e : ans_tail) {
    ans.push_back(e);
  }

  for (int i = 1; i < ans.size(); ++i) {
    if (abs(ans[i - 1] - ans[i]) != 1) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  for (auto e : ans) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
