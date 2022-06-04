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
ll mod = 998244353;
vector<ll> calc_sum(const vector<ll> &dp) {
  ll n = dp.size();
  vector<ll> sum(n);
  rep(i, n) {
    if (i == 0) {
      sum[i] = dp[0];
      continue;
    }
    sum[i] = (sum[i - 1] + dp[i]) % mod;
  }
  return sum;
}
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> dp(m + 1);
  orep(i, m) dp[i] = 1;
  rep(i, n - 1) {
    vector<ll> dp_old(m + 1);
    swap(dp, dp_old);

    vector<ll> dp_sum = calc_sum(dp_old);
    orep(j, m) {
      if (k == 0) {
        dp[j] = dp_sum[m];
        continue;
      }
      if (j + k <= m) {
        dp[j] = (dp_sum[m] - dp_sum[j + k - 1] + mod) % mod;
      }
      if (j - k >= 0) {
        dp[j] = (dp[j] + dp_sum[j - k]) % mod;
      }
    }
  }
  ll ans = 0;
  orep(i, m) { ans = (ans + dp[i]) % mod; }
  cout << ans << endl;
}
