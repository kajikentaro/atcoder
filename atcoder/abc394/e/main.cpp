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
  vector<string> c(n);
  rep(i, n) cin >> c[i];

  vector<vector<int>> dist(n, vector<int>(n, 1e9));

  rep(i, n) rep(j, n) {
    if (c[i][j] != '-') dist[i][j] = 1;
  }
  rep(i, n) dist[i][i] = 0;

  queue<P> que;
  rep(i, n) que.emplace(i, i);
  rep(i, n) rep(j, n) {
    if (c[i][j] != '-') que.emplace(i, j);
  }

  while (que.size()) {
    auto [from, to] = que.front();
    que.pop();

    rep(i, n) rep(j, n) {
      if (c[i][from] == c[to][j] && c[to][j] != '-') {
        if (chmin(dist[i][j], dist[from][to] + 2)) {
          que.emplace(i, j);
        };
      }
    }
  }

  rep(i, n) {
    rep(j, n) {
      int ans = dist[i][j] == 1e9 ? -1 : dist[i][j];
      cout << ans;
      if (j < n - 1) cout << " ";
    }
    cout << endl;
  }
}
