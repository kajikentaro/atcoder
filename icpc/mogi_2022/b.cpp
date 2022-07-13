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
  ll k;
  cin >> k;
  if (k == 0) return false;
  string tmp;
  cin >> tmp;
  // for get answer simply
  tmp = tmp + "0";
  ll n = tmp.size();
  vector<ll> a(n);
  rep(i, n) a[i] = tmp[i] - '0';

  const ll INF = (ll)-1e18;
  vector<vector<ll>> dp(n, vector<ll>(k, INF));

  auto get = [&](ll ni, ll ki) {
    if (ni == -1 && ki == k - 1) return 0ll;
    if (ni < 0 || ki < 0 || ni >= n || ki >= k) return INF;
    return dp[ni][ki];
  };
  rep(ni, n) {
    rep(ki, k) {
      orep(c, k) {
        ll new_val;
        if (ki == 0) {
          new_val = get(ni - c, k - 1) + a[ni] * (ll)pow(10, k - ki - 1);
        } else {
          new_val = get(ni - c, ki - 1) + a[ni] * (ll)pow(10, k - ki - 1);
        }
        chmax(dp[ni][ki], new_val);
      }
    }
  }
  cout << dp[n - 1][0] << endl;
  return true;
}

int main() {
  while (func()) {
    ;
  }
}