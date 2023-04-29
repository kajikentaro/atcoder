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

struct TODO {
  int i, j, k;
};
int sub() {
  int n, m;
  cin >> n >> m;

  vector<int> c(n);
  rep(i, n) cin >> c[i];

  vector<vector<int>> path(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }

  if (c[0] == c[n - 1]) return -1;

  // dp[頂点iについて][1君の色がjのとき][k君が到達可] = 1 or 0
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2)));
  dp[0][0][0] = 1;
  dp[n - 1][0][1] = 1;

  auto isok = [&]() {
    if (dp[0][0][1] == 1 && dp[n - 1][0][0] == 1) return 1;
    if (dp[0][1][1] == 1 && dp[n - 1][1][0] == 1) return 1;
    return 0;
  };

  int cnt = 0;
  while (isok() == 0) {
    cnt++;
    int isMove = 0;
    rep(i, n) {
      rep(j, 2) {
        vector<TODO> todo;
        rep(k, 2) {
          if (dp[i][j][k] == 0) continue;
          for (auto ii : path[i]) {
            int color = c[ii];
            int jj = color != j;
            int kk = k;
            dp[ii][jj][kk] = 1;
            isMove++;
          }
        }
      }
      if (isMove == 0) return -1;
    }
  }
  return cnt;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << sub() << endl;
}