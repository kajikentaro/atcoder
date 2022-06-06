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
int main() {
  int n;
  cin >> n;
  int grid_size = 1010;
  vector<vector<int>> grid(grid_size, vector<int>(grid_size));
  vector<vector<int>> grid_res(grid_size, vector<int>(grid_size));
  rep(i, n) {
    P p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    grid[p1.first][p1.second]++;
    grid[p2.first][p1.second]--;
    grid[p1.first][p2.second]--;
    grid[p2.first][p2.second]++;
  }
  int now = 0;
  rep(x, grid_size) rep(y, grid_size) {
    now += grid[x][y];
    grid_res[x][y] = now;
  }

  swap(grid, grid_res);
  grid_res.resize(0);
  grid_res.resize(grid_size, vector<int>(grid_size));
  now = 0;
  rep(y, grid_size) rep(x, grid_size) {
    now += grid[x][y];
    grid_res[x][y] = now;
  }

  vector<int> ans(n + 1);
  rep(x, grid_size) rep(y, grid_size) { ans[grid_res[x][y]]++; }
  orep(i, n) cout << ans[i] << endl;
}