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
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> s(n - 1);
  rep(i, n - 1) cin >> s[i];
  vector<ll> x(m);
  rep(i, m) cin >> x[i];

  vector<ll> a(n);
  a[0] = 0;
  rep(i, n) {
    if (i == 0) continue;
    a[i] = s[i - 1] - a[i - 1];
  }

  vector<unordered_map<ll, ll>> aa(2);
  rep(i, n) aa[i % 2][a[i]]++;

  ll ans = 0;
  rep(ai, n) rep(xi, m) {
    ll res = 0;
    ll a0_margin = -x[xi] + a[ai];
    if (ai % 2) a0_margin *= -1;
    for (ll xelement : x) {
      res += aa[0][xelement + a0_margin];
      res += aa[1][xelement - a0_margin];
    }
    chmax(ans, res);
  }
  cout << ans << endl;
}