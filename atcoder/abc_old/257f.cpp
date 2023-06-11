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

struct Path {
  int pos;
  Path(int pos) : pos(pos) {}
};
struct Point {
  int time, pos;
  Point(int time, int pos) : time(time), pos(pos) {}
};
bool operator>(const Point &a, const Point &b) { return a.time > b.time; }

int main() {
  int n, m;
  cin >> n >> m;
  // firstが時間、secondが位置
  vector<vector<Path>> path(n);
  vector<int> gate;
  int INF = 1e9;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == -1) {
      gate.push_back(b);
    } else {
      path[a].emplace_back(b);
    }

    if (b == -1) {
      gate.push_back(a);
    } else {
      path[b].emplace_back(a);
    }
  }
  queue<Point> que;
  que.emplace(0, 0);
  vector<int> s_res(n, INF);
  while (que.size()) {
    Point p = que.front();
    que.pop();
    if (s_res[p.pos] != INF) continue;
    s_res[p.pos] = p.time;
    for (auto i : path[p.pos]) {
      que.emplace(p.time + 1, i.pos);
    }
  }

  que.emplace(0, n - 1);
  vector<int> e_res(n, INF);
  while (que.size()) {
    Point p = que.front();
    que.pop();
    if (e_res[p.pos] != INF) continue;
    e_res[p.pos] = p.time;
    for (auto i : path[p.pos]) {
      que.emplace(p.time + 1, i.pos);
    }
  }

  int gate_s_time = INF;
  for (auto g : gate) {
    chmin(gate_s_time, s_res[g]);
  }

  int gate_e_time = INF;
  for (auto g : gate) {
    chmin(gate_e_time, e_res[g]);
  }

  rep(i, n) {
    int s_to_i = min(s_res[i], gate_s_time + 1);
    int i_to_e = min(e_res[i], gate_e_time + 1);

    int ans = min(s_res[n - 1], s_to_i + i_to_e);
    if (ans == INF) {
      cout << -1 << " ";
    } else {
      cout << ans << " ";
    }
  }
  cout << endl;
}