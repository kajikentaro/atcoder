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
using T = tuple<int, int, double>;

signed main() {
  int n, x;
  cin >> n >> x;

  vector<T> Q(n);
  rep(i, n) {
    int s, c, p;
    cin >> s >> c >> p;
    Q[i] = T(s, c, double(p) / 100);
  };

  // dp[i円残っているとき][s]
  vector<vector<double>> dp(x + 1, vector<double>(1 << n));

  rrep(i, x) {
    rep(s, 1 << n) {
      // 問題jを選んでdp[i][s]に来た場合を考える
      rep(j, n) {
        // すでに説かれている場合
        if (s >> j & 1) {
          continue;
        }
        auto [score, c, p] = Q[j];
        if (i + c > x) continue;
        double now =
            p * (dp[i + c][s | 1 << j] + score) + (1 - p) * (dp[i + c][s] + 0);
        chmax(dp[i][s], now);
      }
    }
  }

  double ans = 0;
  rep(s, 1 << n) { chmax(ans, dp[0][s]); }
  printf("%.10f\n", ans);
}