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

struct Point {
  int h, w, cost;
  Point(int h, int w, int cost) : h(h), w(w), cost(cost) {}
};

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
  queue<Point> que;
  que.emplace(h1, w1, 0);

  vector<vector<int>> res(h, vector<int>(w, -1));
  while (que.size()) {
    Point p = que.front();
    que.pop();

    int dict[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto d : dict) {
      int hi = p.h;
      int wi = p.w;
      while (1) {
        hi += d[0];
        wi += d[1];
        if (hi < 0 || wi < 0 || hi >= h || wi >= w) break;
        if (grid[hi][wi] == '#') break;
        if (res[hi][wi] != -1) break;
        res[hi][wi] = p.cost + 1;

        que.emplace(hi, wi, p.cost + 1);
      }
    }
  }

  res[h1][w1] = 1;
  cout << res[h2][w2] - 1 << endl;
}