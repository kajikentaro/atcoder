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
// dp[i個目の餌を][買う/買わない][n-1個目を買ったかどうか]
ll dp[300010][2][2] = {};
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  dp[0][0][0] = 1e18;
  dp[0][1][0] = a[0];

  dp[0][0][1] = a[n - 1];
  dp[0][1][1] = a[0] + a[n - 1];

  rep(i, n) {
    if (i == 0) continue;
    dp[i][0][0] = dp[i - 1][1][0];
    dp[i][1][0] = min(dp[i - 1][0][0] + a[i], dp[i - 1][1][0] + a[i]);

    if (i == n - 1) {
      dp[i][0][1] = dp[i - 1][1][1];
      dp[i][1][1] = min(dp[i - 1][0][1], dp[i - 1][1][1]);
      break;
    }
    dp[i][0][1] = dp[i - 1][1][1];
    dp[i][1][1] = min(dp[i - 1][0][1] + a[i], dp[i - 1][1][1] + a[i]);
  }

  ll mi = 1e18;
  chmin(mi, dp[n - 1][0][0]);
  chmin(mi, dp[n - 1][0][1]);
  chmin(mi, dp[n - 1][1][0]);
  chmin(mi, dp[n - 1][1][1]);
  cout << mi << endl;
}