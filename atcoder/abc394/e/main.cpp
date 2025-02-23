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
  int next;
  char label;
  P(int next, char label) : next(next), label(label) {}
};

signed main() {
  int n;
  cin >> n;
  vector<string> path(n);
  vector<vector<int>> cost(n, vector<int>(n, 1e9));
  rep(i, n) cin >> path[i];

  rep(i, n) rep(j, n) {
    if (path[i][j] != '-') cost[i][j] = 1;
  }

  rep(i, n) rep(j, n) rep(k, n) {
    if (path[i][j] == path[j][k] && path[j][k] != '-') {
      chmin(cost[i][j], 2ll);
    }
  }
  rep(i, n) rep(j, n) rep(k, n) rep(l, n) {
    if (path[i][j] == path[k][l] && path[k][l] != '-' && path[j][k] != '-') {
      chmin(cost[i][l], 3ll);
    }
  }
}
