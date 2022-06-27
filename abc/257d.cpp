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
struct Gate {
  ll x, y, power;
};
int main() {
  ll n;
  cin >> n;

  vector<Gate> gates;
  rep(i, n) {
    Gate p;
    cin >> p.x >> p.y >> p.power;
    gates.push_back(p);
  }

  vector<vector<Path>> path(n);
  rep(from, n) rep(to, n) {
    if (from == to) continue;
    ll tmp_dist =
        abs(gates[from].x - gates[to].x) + abs(gates[from].y - gates[to].y);
    ll time = (tmp_dist + gates[from].power - 1) / gates[from].power;
    path[from].emplace_back(time, to);
  }

  ll ans = 1e18;
  rep(start, n) {
    priority_queue<Point, vector<Point>, greater<Point>> que;
    que.emplace(0, start);
    vector<ll> res(n, -1);
    while (que.size()) {
      Point p = que.top();
      que.pop();
      if (res[p.pos] != -1) continue;
      res[p.pos] = p.time;
      for (auto i : path[p.pos]) {
        que.emplace(max(p.time, i.time), i.pos);
      }
    }
    ll s_ans = 0;
    for (auto r : res) {
      chmax(s_ans, r);
    }
    chmin(ans, s_ans);
  }
  cout << ans << endl;
}