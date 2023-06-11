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
//頂点1からnまでの最短経路を求めるプログラム
struct Path {
  int time, pos, idx;
  Path(int time, int pos, int idx) : time(time), pos(pos), idx(idx) {}
};
struct Point {
  int time, pos, path_from;
  Point(int time, int pos, int path_from)
      : time(time), pos(pos), path_from(path_from) {}
};
bool operator>(const Point &a, const Point &b) {
  if (a.time == b.time) return a.path_from > b.path_from;
  return a.time > b.time;
}
int main() {
  int n, m;
  cin >> n >> m;
  // firstが時間、secondが位置
  vector<vector<Path>> path(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    path[a].emplace_back(c, b, i);
    path[b].emplace_back(c, a, i);
  }

  vector<bool> used_path(m, false);
  rep(i, n) {
    priority_queue<Point, vector<Point>, greater<Point>> que;
    que.emplace(0, i, -1);
    vector<int> res(n, -1);
    while (que.size()) {
      Point p = que.top();
      que.pop();
      if (res[p.pos] != -1) continue;
      res[p.pos] = p.time;
      if (p.path_from != -1) used_path[p.path_from] = true;
      for (auto i : path[p.pos]) {
        que.emplace(p.time + i.time, i.pos, i.idx);
      }
    }
  }

  ll ans = 0;
  rep(i, m) if (used_path[i] == false) ans++;
  cout << ans << endl;
}