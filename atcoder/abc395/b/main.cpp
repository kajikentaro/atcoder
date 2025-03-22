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

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));

  auto draw = [&](int from, int length) {
    int c = from;
    int fixed = from;
    rep(i, length) {
      a[fixed][c] = 1;
      a[c][fixed] = 1;
      a[n - 1 - from][c] = 1;
      a[c][n - 1 - from] = 1;
      c++;
    }
  };

  int width = n;
  rep(i, n) {
    if (width <= 0) break;
    draw(i, width);
    width -= 4;
    i++;
  }

  rep(i, n) {
    rep(j, n) { cout << (a[i][j] ? "#" : "."); }
    cout << endl;
  }
}