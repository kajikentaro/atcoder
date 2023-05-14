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
using P = pair<int, int>;
using mint = modint1000000007;

int h, w, t;

int point_to_idx(int hi, int wi) { return hi * w + wi; }

struct Pos {
  P to;
  int dist;
  int isokashi;
};

vector<string> grid;
char get_grid(P now) { return grid[now.first][now.second]; }

struct DK {
  int hi, wi, okashi, time, isokashi;
};

bool operator>(const DK &a, const DK &b) { return a.time > b.time; }
bool operator<(const DK &a, const DK &b) { return a.time < b.time; }

signed main() {
  cin >> h >> w >> t;

  grid.resize(h);
  rep(i, h) cin >> grid[i];

  vector<P> dictionary(2);
  {
    rep(hi, h) rep(wi, w) {
      if (grid[hi][wi] == 'S') {
        dictionary[0].first = hi;
        dictionary[0].second = wi;
      }
      if (grid[hi][wi] == 'G') {
        dictionary[1].first = hi;
        dictionary[1].second = wi;
      }
    }
    rep(hi, h) rep(wi, w) {
      if (grid[hi][wi] == 'o') {
        dictionary.emplace_back(hi, wi);
      }
    }
  }

  map<P, vector<Pos>> path;
  for (auto from : dictionary) {
    map<P, bool> used;
    queue<pair<P, int>> que;
    que.emplace(from, 0);

    while (que.size()) {
      pair<P, int> now = que.front();
      que.pop();
      if (used[now.first]) continue;
      used[now.first] = true;

      if (get_grid(now.first) == 'o') {
        path[from].push_back(Pos{now.first, now.second, true});
      }
      if (get_grid(now.first) == 'S') {
        path[from].push_back(Pos{now.first, now.second, false});
      }
      if (get_grid(now.first) == 'G') {
        path[from].push_back(Pos{now.first, now.second, false});
      }
      int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
      for (auto d : dirs) {
        pair<P, int> next = now;
        next.first.first += d[0];
        next.first.second += d[1];
        next.second++;
        if (next.first.first < 0 || next.first.first >= h) continue;
        if (next.first.second < 0 || next.first.second >= w) continue;
        if (get_grid(next.first) == '#') continue;
        que.push(next);
      }
    }
  }

  priority_queue<DK, vector<DK>, greater<DK>> que;
  que.push(DK{dictionary[0].first, dictionary[0].second, 0, 0});
  map<DK, DK> res;
  while (que.size()) {
    DK p = que.top();
    que.pop();

    DK key = p;
    p.time = 0;
    p.isokashi = 0;
    if (res.count(key) != 0) continue;
    res[key] = p;
    for (auto i : path[P{p.hi, p.wi}]) {
      if (p.time + i.dist > t) continue;
      if (i.isokashi)
        que.push(DK{i.to.first, i.to.second, p.okashi + 1, p.time + i.dist});
      else
        que.push(DK{i.to.first, i.to.second, p.okashi, p.time + i.dist});
    }
  }

  DK fin;
  fin.hi = dictionary[1].first;
  fin.wi = dictionary[1].second;

  int ans = 0;
  rep(i, 20) {
    fin.okashi = i;
    if (res.count(fin) > 0) chmax(ans, i);
  }

  cout << ans << endl;
}
