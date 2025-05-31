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

int SEARCH_MAX = 2e6;

vector<bool> ok(SEARCH_MAX);
map<P, bool> used;
int h, w;

P p_to_hw(int p) {
  int wi = p % w;
  int hi = p / w;
  return P(hi, wi);
}

void dfs(int g, int p) {
  if (p == h * w) {
    ok[g] = true;
    return;
  }
  if (used[P(g, p)]) return;
  used[P(g, p)] = true;
  // not place
  dfs(g, p + 1);

  // already placed
  if (g >> p & 1) return;

  P phw = p_to_hw(p);

  // place |
  if (phw.first < h - 1) {
    int p2 = p + w;
    dfs(g | 1 << p | 1 << p2, p + 1);
  }

  // place -
  if (phw.second < w - 1) {
    int p2 = p + 1;
    if (g >> p2 & 1) return;
    dfs(g | 1 << p | 1 << p2, p + 1);
  }
}

signed main() {
  cin >> h >> w;
  vector<vector<int>> ma(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> ma[i][j];

  dfs(0, 0);

  int ans = -1;
  rep(now_g, SEARCH_MAX) {
    if (!ok[now_g]) {
      continue;
    }
    int tmp = 0;
    rep(j, h * w) {
      if (!(now_g >> j & 1)) {
        P p = p_to_hw(j);
        tmp ^= ma[p.first][p.second];
      }
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
}