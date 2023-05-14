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

struct P {
  int x, y, z;
};

int dist(const P &a, const P &b) {
  return abs(a.x - b.x) + abs(a.y - b.y) + max(0LL, b.z - a.z);
}

// 頂点0からスタートしてすべての点を1回以上経由して頂点0に戻る時の最短路計算
signed main() {
  int n;
  cin >> n;

  vector<P> pos(n);
  rep(i, n) cin >> pos[i].x >> pos[i].y >> pos[i].z;

  const int inf = 1e9;
  vector<vector<int>> dp(1 << n, vector<int>(n, inf));

  rep(i, n) {
    if (i == 0) continue;
    dp[1 << i][i] = dist(pos[0], pos[i]);
  }
  rep(i, 1 << n) {  // 譜面iに対して
    rep(j, n) {     // jから出発して
      if (((i >> j) & 1) == 0) continue;

      rep(k, n) {  // kに到達する場合を考える
        if (((i >> k) & 1) == 1) {
          // 既に訪れたところにもう一度いかない
          continue;
        }
        chmin(dp[i | (1 << k)][k], dp[i][j] + dist(pos[j], pos[k]));
      }
    }
  }

  cout << dp[(1 << n) - 1][0] << endl;
}
