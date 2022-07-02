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
  ll n, m;
  cin >> n >> m;
  if (n + m == 0) return false;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, n) for (int j = i + 1; j < n; j++) {
    ll sum = a[i] + a[j];
    if (sum <= m) chmax(ans, sum);
  }
  if (ans == 0) {
    cout << "NONE" << endl;
  } else {
    cout << ans << endl;
  }
  return true;
}
int main() {
  while (func()) {
    ;
  }
}