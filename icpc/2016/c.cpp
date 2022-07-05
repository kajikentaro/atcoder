#include <bits/stdc++.h>

#include <atcoder/all>
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

bool func() {
  int m, n;
  cin >> m >> n;
  if (m == 0 && n == 0) return false;

  ll SEARCH_MAX = 1e7;
  vector<bool> table(SEARCH_MAX);

  int cnt = 0;
  ll recent = -1;
  ll i;
  for (i = m; true; i++) {
    if (table[i] == true) continue;
    cnt++;
    for (ll j = i; j < SEARCH_MAX; j += i) {
      table[j] = true;
    }
    if (cnt == n) {
      recent = i;
      break;
    }
  }

  ll burn;
  for (ll i = recent; i < SEARCH_MAX; i++) {
    if (table[i] == true) continue;
    burn = i;
    break;
  }

  cout << burn << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}