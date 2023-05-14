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

int h, w, t;
vector<string> grid;

struct Path {
  int to, time;
  Path(int to, int time) : to(to), time(time) {}
  Path() {}
};

struct P {
  int hi, wi;
  P(int hi, int wi) : hi(hi), wi(wi) {}
  P() {}
};

signed main() {
  cin >> h >> w >> t;

  grid.resize(h);
  rep(i, h) cin >> grid[i];

  vector<P> dictionary(2);
  {
    rep(hi, h) rep(wi, w) {
      if (grid[hi][wi] == 'S') {
        dictionary[0].hi = hi;
        dictionary[0].wi = wi;
      }
      if (grid[hi][wi] == 'G') {
        dictionary[1].hi = hi;
        dictionary[1].wi = wi;
      }
    }
    rep(hi, h) rep(wi, w) {
      if (grid[hi][wi] == 'o') {
        dictionary.emplace_back(hi, wi);
      }
    }
  }

  vector<vector<Path>> path(dictionary.size());
  rep(i, dictionary.size()) {
    rep(j, dictionary.size()) {
      if (i == j) continue;
      struct Now {
        int hi, wi, time;
        Now(int _hi, int _wi, int _time) : hi(_hi), wi(_wi), time(_time) {}
      };
      vector<vector<bool>> used(h, vector<bool>(w));
      queue<Now> que;
      que.emplace(dictionary[i].hi, dictionary[i].wi, 0);

      while (que.size()) {
        Now now = que.front();
        que.pop();
        if (used[now.hi][now.wi]) continue;
        used[now.hi][now.wi] = true;

        if (now.hi == dictionary[j].hi && now.wi == dictionary[j].wi) {
          path[i].emplace_back(j, now.time);
        }

        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto d : dirs) {
          Now next = now;
          next.hi = now.hi + d[0];
          next.wi = now.wi + d[1];
          next.time = now.time + 1;
          if (next.hi < 0 || next.wi < 0) continue;
          if (next.hi >= h || next.wi >= w) continue;
          if (grid[next.hi][next.wi] == '#') continue;
          que.push(next);
        }
      }
    }
  }

  int n = dictionary.size();
  const int inf = 1e9;
  vector<vector<int>> dp(1 << n, vector<int>(n, inf));

  dp[1 << 0][0] = 0;

  rep(i, 1 << n) {  // 譜面iに対して
    rep(j, n) {     // jから出発して
      if (((i >> j) & 1) == 0) continue;

      for (auto next : path[j]) {
        if (((i >> next.to) & 1) == 1) {
          // 既に訪れたところにもう一度いかない
          continue;
        }
        chmin(dp[i | (1 << next.to)][next.to], dp[i][j] + next.time);
      }
    }
  }

  int ans = -1;
  rep(i, 1 << n) {
    if (dp[i][1] > t) continue;
    int score = 0;
    int ii = i;
    while (ii != 0) {
      if (ii % 2) score++;
      ii /= 2;
    }
    chmax(ans, score - 2);
  }

  cout << ans << endl;
}