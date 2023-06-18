#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(x, y) for (int x = 0; x < y; x++)

int main() {
  // main
  vector<ll> prime;
  ll SEARCH_MAX = 1e6 + 10;
  vector<bool> tmp(SEARCH_MAX);
  for (ll i = 2; i * i <= SEARCH_MAX; i++) {
    if (tmp[i] == true) continue;
    for (ll j = i * 2; j < SEARCH_MAX; j += i) {
      tmp[j] = true;
    }
  }
  rep(i, SEARCH_MAX) {
    if (i < 2) continue;
    if (tmp[i] == 0) prime.push_back(i);
  }

  // output
  for (auto p : prime) {
    cout << p << endl;
  }
}