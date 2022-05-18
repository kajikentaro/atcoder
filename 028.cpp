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
  int grid[1010][1010] = {};
  rep(i, n) {
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    grid[sx][sy]++;
    grid[dx][dy]--;
  }
  int now = 0;

  int k[100010] = {};
  rep(i, 1005) rep(j, 1005) {
    now += grid[i][j];
    k[now]++;
  }
  orep(i, n) { cout << k[i] << endl; }
}