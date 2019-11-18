#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> divisors;
  long long sqr = sqrt(n);
  for (long long i = 2; i <= sqr; ++i) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
    while(n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) {
    divisors.push_back(n);
  }
  if (divisors.size() == 0) {
    cout << 1 << endl;
  } else if (divisors.size() > 1) {
    cout << 1 << endl;
  } else {
    cout << divisors[0] << endl;
  }
  return 0;

