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
  // tdpc e
  string n;
  int k;
  cin >> n >> k;
  int ns = n.size();
  // dp[i][j][f]: i桁目まで見た時、0出ない数字をk個使った時の場合の数
  vector<vector<vector<int>>> dp(ns + 10,
                                 vector<vector<int>>(k + 10, vector<int>(2)));
  dp[0][0][1] = 1;

  rep(keta, ns) {
    rep(ki, k + 1) {
      rep(num, 10) {
        if (num == 0) {
          dp[keta + 1][ki][0] += dp[keta][ki][0];
          if (num == n[keta] - '0') {
            dp[keta + 1][ki][1] += dp[keta][ki][1];
          }
          if (num < n[keta] - '0') {
            dp[keta + 1][ki][0] += dp[keta][ki][1];
          }
          if (num > n[keta] - '0') {
            // 不可能なケース
            exit(1);
          }
        } else {
          dp[keta + 1][ki + 1][0] += dp[keta][ki][0];
          if (num == n[keta] - '0') {
            dp[keta + 1][ki + 1][1] += dp[keta][ki][1];
          }
          if (num < n[keta] - '0') {
            dp[keta + 1][ki + 1][0] += dp[keta][ki][1];
          }
          if (num > n[keta] - '0') continue;
        }
      }
    }
  }
  int ans = dp[ns][k][1] + dp[ns][k][0];
  cout << ans << endl;
}
