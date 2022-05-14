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

struct Point {
  int h, w, cost, dir;
  Point(int h, int w, int cost, int dir) : h(h), w(w), cost(cost), dir(dir) {}
};

bool operator>(const Point &a, const Point &b) { return a.cost > b.cost; }
int cost[1010][1010][4];
int main() {
  int h, w;
  cin >> h >> w;
  int h1, w1, h2, w2;
  cin >> h1 >> w1 >> h2 >> w2;
  h1--;
  w1--;
  h2--;
  w2--;
  vector<string> grid(h);
  rep(i, h) { cin >> grid[i]; }
  priority_queue<Point, vector<Point>, greater<Point>> que;
  que.emplace(h1, w1, 0, 0);
  que.emplace(h1, w1, 0, 1);
  que.emplace(h1, w1, 0, 2);
  que.emplace(h1, w1, 0, 3);

  rep(i, h) rep(j, w) rep(k, 4) { cost[i][j][k] = -1; }
  while (que.size()) {
    Point p = que.top();
    que.pop();
    if (p.h < 0 || p.w < 0 || p.h >= h || p.w >= w) continue;
    if (grid[p.h][p.w] == '#') continue;
    if (cost[p.h][p.w][p.dir] != -1) continue;
    cost[p.h][p.w][p.dir] = p.cost;

    const P dir[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    rep(i, 4) {
      int hi = p.h + dir[i].first;
      int wi = p.w + dir[i].second;
      int cost_i = p.cost + 1;
      if (p.dir == -1 || p.dir == i) {
        cost_i = p.cost;
      }
      Point new_p(hi, wi, cost_i, i);
      que.push(new_p);
    }
  }
  int mi = 1e9;
  rep(i, 4) {
    if (cost[h2][w2][i] == -1) continue;
    chmin(mi, cost[h2][w2][i]);
  }
  cout << mi << endl;
}