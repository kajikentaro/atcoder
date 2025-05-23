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
  ll time, pos;
  Path(ll time, ll pos) : time(time), pos(pos) {}
};
struct Point {
  ll time, pos;
  Point(ll time, ll pos) : time(time), pos(pos) {}
};
bool operator>(const Point &a, const Point &b) { return a.time > b.time; }
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> height(n);
  rep(i, n) cin >> height[i];
  // firstが時間、secondが位置
  vector<vector<Path>> path(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].emplace_back(max(0ll, height[b] - height[a]), b);
    path[b].emplace_back(max(0ll, height[a] - height[b]), a);
  }
  priority_queue<Point, vector<Point>, greater<Point>> que;
  que.emplace(0, 0);
  vector<ll> res(n, -1);
  while (que.size()) {
    Point p = que.top();
    que.pop();
    if (res[p.pos] != -1) continue;
    res[p.pos] = p.time;
    for (auto i : path[p.pos]) {
      que.emplace(p.time + i.time, i.pos);
    }
  }

  ll ans = 0;
  rep(i, n) {
    ll hate = res[i];
    ll fun = height[0] - height[i];
    ll ans_tmp = fun - hate;
    chmax(ans, ans_tmp);
  }
  cout << ans << endl;
}