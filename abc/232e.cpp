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
using mint = modint998244353;
using P = pair<int, int>;
int is_touch_edge(ll idx, ll length) {
  if (idx == 1) return 1;
  if (idx == length) return 1;
  return 0;
}
int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  ll sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  // dp[真ん中、端、角][スタート位置、距離1の位置、それ以外]
  vector<vector<mint>> dp(3, vector<mint>(3));

  int edge_cnt = is_touch_edge(sx, w);
  edge_cnt += is_touch_edge(sy, h);

  dp[edge_cnt][0] = 1;

  rep(i, k) {
    vector<vector<mint>> dp_old(3, vector<mint>(3));
    swap(dp_old, dp);

    dp[0][1] += dp_old[0][0];
    dp[0][1] += dp_old[0][0];
  }
}