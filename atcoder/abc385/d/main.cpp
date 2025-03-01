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
  map<char, vector<int>> dirs;
  dirs['U'] = {0, 1};
  dirs['D'] = {0, -1};
  dirs['L'] = {-1, 0};
  dirs['R'] = {1, 0};

  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  map<int, set<int>> house_x;
  map<int, set<int>> house_y;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    house_x[x].insert(y);
    house_y[y].insert(x);
  }

  int ans = 0;
  rep(i, m) {
    char d;
    int c;
    cin >> d >> c;

    int dx = dirs[d][0] * c;
    int dy = dirs[d][1] * c;

    set<int> *se;
    int a, b;
    if (dx == 0) {
      se = &house_x[sx];
      a = sy;
      b = sy + dy;
    }
    if (dy == 0) {
      se = &house_y[sy];
      a = sx;
      b = sx + dx;
    }

    if (a > b) swap(a, b);  // a is small
    auto itr_a = se->lower_bound(a);
    auto itr_b = se->upper_bound(b);
    int cnt = 0;
    vector<int> to_be_remove;
    while (itr_a != itr_b) {
      to_be_remove.push_back(*itr_a);
      ++itr_a;
      ++cnt;
    }
    ans += cnt;

    for (auto &tt : to_be_remove) {
      int x, y;
      if (dx == 0) {
        x = sx;
        y = tt;
      }
      if (dy == 0) {
        x = tt;
        y = sy;
      }

      house_x[x].erase(y);
      house_y[y].erase(x);
    }

    sx += dx;
    sy += dy;
  }

  cout << sx << " " << sy << " " << ans << endl;
}
