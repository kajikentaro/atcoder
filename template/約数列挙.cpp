#include <bits/stdc++.h>
#define rep(x, y) for (int x = 0; x < y; x++)
using namespace std;
int main() {
  // input
  int n = 12;

  // main
  vector<int> k;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      k.push_back(i);
    } else if (n % i == 0) {
      k.push_back(i);
      k.push_back(n / i);
    }
  }

  // output
  for (auto kk : k) {
    cout << kk << endl;
  }
}