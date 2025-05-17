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

signed main() {
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  vector<vector<bool>> used(h, vector<bool>(w));
  queue<P> que;
  rep(i, h) rep(j, w) {
    if (grid[i][j] == 'E') {
      used[i][j] = true;
      que.emplace(i, j);
    }
  }

  vector<string> ans = grid;

  const vector<P> DIRS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  const vector<char> CHARS = {'v', '<', '^', '>'};
  while (que.size()) {
    auto [hi, wi] = que.front();
    que.pop();
    rep(_t, 4) {
      auto d = DIRS[_t];
      char c = CHARS[_t];
      int hi2 = hi + d.first;
      int wi2 = wi + d.second;

      if (!(0 <= hi2 && hi2 < h && 0 <= wi2 && wi2 < w)) {
        continue;
      }
      if (used[hi2][wi2]) continue;
      if (grid[hi2][wi2] == '#') continue;

      used[hi2][wi2] = true;
      ans[hi2][wi2] = c;
      que.emplace(hi2, wi2);
    }
  };

  rep(i, h) { cout << ans[i] << endl; }
}