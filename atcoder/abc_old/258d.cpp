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
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i] >> b[i];

  ll ans = 9e18;
  ll now = 0;
  rep(i, min(n, x)) {
    now += a[i] + b[i];
    ll remain_time = x - (i + 1);

    ll s_ans = remain_time * b[i] + now;
    chmin(ans, s_ans);
  }

  cout << ans << endl;
}