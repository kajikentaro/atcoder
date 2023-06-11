#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;

vector<vector<int>> path;
int dfs(int p, int depth, vector<int> used, int &init_p) {
  if (init_p == p && used[p]) return depth;
  if (used[p]) return -1;
  used[p] = 1;
  int ma = -1;
  for (auto new_p : path[p]) {
    int res = dfs(new_p, depth + 1, used, init_p);
    chmax(ma, res);
  }
  return ma;
};
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  int n = h * w;
  path.resize(n);
  rep(i, h) rep(j, w) {
    if (grid[i][j] == '#') continue;
    const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int p = i * w + j;
    for (auto d : directions) {
      int i2 = i + d[0];
      int j2 = j + d[1];
      if (i2 < 0 || i2 >= h || j2 < 0 || j2 >= w) continue;
      int p2 = i2 * w + j2;
      path[p].push_back(p2);
    }
  }

  int ans = -1;
  rep(i, n) {
    vector<int> used(n);
    int res = dfs(i, 0, used, i);
    if (res == 2) continue;
    chmax(ans, res);
  }
  cout << ans << endl;
}