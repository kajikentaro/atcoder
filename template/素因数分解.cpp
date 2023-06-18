#include <bits/stdc++.h>
#define rep(x, y) for (int x = 0; x < y; x++)
using namespace std;
int main() {
  // input
  int n = 12;

  // main
  vector<int> k;
  for (int i = 2; i * i <= n;) {
    if (n % i == 0) {
      k.push_back(i);
      n /= i;
      continue;
    } else {
      i++;
    }
  }
  if (n != 1) k.push_back(n);

  // output
  for (auto kk : k) {
    cout << kk << endl;
  }
}