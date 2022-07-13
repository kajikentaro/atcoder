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

int h, w;
vector<vector<int>> grid;

ll injection(int h_min, int h_max, int w_min, int w_max) {
  int wall_min = 1e9;
  int in_max = 0;

  int size = 0;

  ll height_sum = 0;
  rep(hi, h) rep(wi, w) {
    auto is_in = [&]() {
      return h_min < hi && hi < h_max && w_min < wi && wi < w_max;
    };
    auto is_out = [&]() {
      return hi < h_min || h_max < hi || wi < w_min || w_max < wi;
    };
    auto is_wall = [&]() {
      if (is_in()) return false;
      if (is_out()) return false;
      return true;
    };
    if (is_wall()) {
      // wall
      chmin(wall_min, grid[hi][wi]);
    }
    if (is_in()) {
      // in wall
      chmax(in_max, grid[hi][wi]);
      height_sum += grid[hi][wi];
      size++;
    }
  }
  if (in_max >= wall_min) return 0;
  if (size == 0) return 0;

  ll ans = size * wall_min;
  ans -= height_sum;
  return ans;
}

bool func() {
  cin >> h >> w;
  if (h + w == 0) return false;
  grid.assign(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> grid[i][j];

  ll ans = 0;

  for (int h_min = 0; h_min < h; h_min++) {
    for (int h_max = h_min + 1; h_max < h; h_max++) {
      for (int w_min = 0; w_min < w; w_min++) {
        for (int w_max = w_min + 1; w_max < w; w_max++) {
          ll s_ans = injection(h_min, h_max, w_min, w_max);
          chmax(ans, s_ans);
        }
      }
    }
  }

  cout << ans << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}