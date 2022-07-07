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
using mint = modint998244353;
using P = pair<int, int>;
struct Point {
  int x, y;
};

vector<vector<long long>> comb(int n) {
  vector<vector<long long>> v(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  Point s, t;
  cin >> s.x >> s.y >> t.x >> t.y;

  // [0]: s, [1]: normal
  vector<vector<mint>> x(k + 1, vector<mint>(2));
  vector<vector<mint>> y(k + 1, vector<mint>(2));

  x[0][0] = 1;
  y[0][0] = 1;
  orep(i, k) {
    x[i][1] = x[i - 1][0] + (w - 2) * x[i - 1][1];
    x[i][0] = x[i - 1][1] * (w - 1);

    y[i][1] = y[i - 1][0] + (h - 2) * y[i - 1][1];
    y[i][0] = y[i - 1][1] * (h - 1);
  }
  mint ans = 0;
  int x_idx = s.x != t.x;
  int y_idx = s.y != t.y;

  vector<vector<ll>> C = comb(k + 10);

  rep(i, k + 1) {
    ans += C[k][i] * x[i][x_idx] * y[k - i][y_idx];
    ;
  }

  cout << ans.val() << endl;
}