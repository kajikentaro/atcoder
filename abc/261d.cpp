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
  vector<ll> x(n);
  vector<ll> y(n + 1);
  rep(i, n) cin >> x[i];
  rep(i, m) {
    ll c;
    cin >> c;
    cin >> y[c];
  }
  vector<ll> dp(n + 1, -1);
  dp[0] = 0;
  for (ll bonous : x) {
    vector<ll> dp_old(n + 1, -1);
    swap(dp, dp_old);

    // reset
    rep(j, n) chmax(dp[0], dp_old[j]);

    orep(j, n) {
      if (dp_old[j - 1] == -1) continue;
      dp[j] = dp_old[j - 1] + y[j] + bonous;
    }
  }
  ll ans = 0;
  rep(i, n + 1) { chmax(ans, dp[i]); }
  cout << ans << endl;
}