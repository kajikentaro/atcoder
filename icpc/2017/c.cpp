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
struct Point {
  int h, w;
};

int h, w;
vector<vector<int>> grid;
vector<vector<int>> used_global;
vector<vector<int>> used;
int wall_min;
void dfs(int level, Point now) {
  const Point dirs[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
  if (used[now.h][now.w]) return;
  used[now.h][now.w] = 1;
  for (auto d : dirs) {
    Point next = now;
    next.h += d.h;
    next.w += d.w;
    if (next.h < 0 || next.w < 0 || next.h >= h || next.w >= w) continue;
    if (grid[next.h][next.w] > level) {
      chmin(wall_min, grid[next.h][next.w]);
      continue;
    }
    dfs(level, next);
  }
}

ll injection(Point start) {
  used.assign(h, vector<int>(w));
  int level = grid[start.h][start.w];
  wall_min = 1e9;
  dfs(level, start);

  ll bonus = 0;
  ll used_block = 0;

  rep(hi, h) rep(wi, w) {
    if (!used[hi][wi]) continue;
    used_block++;
    bool is_edge = (hi == 0 || wi == 0 || hi == h - 1 || wi == w - 1);
    if (is_edge && used[hi][wi]) return 0;
    bonus += level - grid[hi][wi];
  }

  ll base_score = (wall_min - level) * used_block;
  ll ans = bonus + base_score;
  return ans;
}

bool func() {
  cin >> h >> w;
  grid.resize(h, vector<int>(w));
  used_global.resize(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> grid[i][j];

  ll ans = 0;
  rep(hi, h) rep(wi, w) {
    if (hi == 0 || wi == 0 || hi == h - 1 || wi == w - 1) continue;
    if (used_global[hi][wi]) continue;
    ll s_ans = injection(Point{hi, wi});
    chmax(ans, s_ans);
  }
  cout << ans << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}