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

int h, w;
vector<string> grid;
int dfs(int hi, int wi, int start_h, int start_w, int depth, set<P> used) {
  if (hi < 0 || wi < 0 || hi >= h || wi >= w) return -1;
  if (grid[hi][wi] == '#') return -1;
  if (used.count({hi, wi})) {
    if (hi == start_h && wi == start_w) return depth;
    return -1;
  }
  used.insert({hi, wi});
  int ans = -1;
  const int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
  for (auto d : dirs) {
    int hj = hi + d[0];
    int wj = wi + d[1];
    int res = dfs(hj, wj, start_h, start_w, depth + 1, used);
    if (res != 2) chmax(ans, res);
  }
  return ans;
}
int main() {
  cin >> h >> w;
  grid.resize(h);
  rep(i, h) cin >> grid[i];

  int ans = -1;
  rep(i, h) rep(j, w) {
    set<P> used;
    chmax(ans, dfs(i, j, i, j, 0, used));
  }
  cout << ans << endl;
}
