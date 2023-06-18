#include <bits/stdc++.h>

#include <atcoder/all>
#define int long long
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  return a < b ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  return b < a ? (a = b, 1) : 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;

signed main() {
  // main
  ll SEARCH_MAX = 1e7 + 10;
  vector<int> eratosthenes(SEARCH_MAX);
  // i * i <= SEARCH_MAXではないので注意
  for (ll i = 2; i <= SEARCH_MAX; i++) {
    if (eratosthenes[i] >= 1) continue;
    for (ll j = i; j < SEARCH_MAX; j += i) {
      ++eratosthenes[j];
    }
  }

  // output
  int t = 2 * 2 * 3 * 5 * 11;
  cout << eratosthenes[t] << endl;  // 4
}