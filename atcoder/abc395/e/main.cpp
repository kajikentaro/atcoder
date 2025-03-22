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

struct Path {
  int time, pos;
  Path(int time, int pos) : time(time), pos(pos) {}
};
struct Point {
  int time, pos;
  Point(int time, int pos) : time(time), pos(pos) {}
};
bool operator>(const Point &a, const Point &b) { return a.time > b.time; }
signed main() {
  int n, m, x;
  cin >> n >> m >> x;
  n *= 2;
  // firstが時間、secondが位置
  vector<vector<Path>> path(n);
  rep(i, m) {
    int a, b, c;
    c = 1;
    cin >> a >> b;
    a--;
    b--;
    path[a].emplace_back(c, b);
    path[b + n / 2].emplace_back(c, a + n / 2);
  }
  rep(i, n / 2) {
    path[i].emplace_back(x, i + n / 2);
    path[i + n / 2].emplace_back(x, i);
  }
  priority_queue<Point, vector<Point>, greater<Point>> que;
  que.emplace(0, 0);
  vector<int> res(n, -1);
  while (que.size()) {
    Point p = que.top();
    que.pop();
    if (res[p.pos] != -1) continue;
    res[p.pos] = p.time;
    for (auto i : path[p.pos]) {
      que.emplace(p.time + i.time, i.pos);
    }
  }
  int ans = min(res[n - 1], res[n / 2 - 1]);
  cout << ans << endl;
}