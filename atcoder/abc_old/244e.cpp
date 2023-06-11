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
int main() {
  int n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  s--;
  t--;
  x--;

  vector<vector<int>> path(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    path[u].push_back(v);
    path[v].push_back(u);
  }

  // dp[点][xが出現した個数 % 2]
  vector<vector<mint>> dp(n, vector<mint>(2));
  dp[s][x == s] = 1;

  rep(i, k) {
    vector<vector<mint>> dp_old(n, vector<mint>(2));
    swap(dp, dp_old);
    rep(p, n) {
      for (int np : path[p]) {
        int x_flag = np == x;
        dp[np][0 ^ x_flag] += dp_old[p][0];
        dp[np][1 ^ x_flag] += dp_old[p][1];
      }
    }
  }
  cout << dp[t][0].val() << endl;
}