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
using P = pair<int, int>;

signed main() {
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  rep(hi, h) { cin >> grid[hi]; }

  int hi_ma = -1, hi_mi = 1e9;
  int wi_ma = -1, wi_mi = 1e9;
  rep(hi, h) {
    rep(wi, w) {
      if (grid[hi][wi] == '#') {
        chmax(hi_ma, hi);
        chmin(hi_mi, hi);
        chmax(wi_ma, wi);
        chmin(wi_mi, wi);
      }
    }
  }

  for (int hi = hi_mi; hi <= hi_ma; hi++) {
    for (int wi = wi_mi; wi <= wi_ma; wi++) {
      if (grid[hi][wi] == '.') {
        cout << hi + 1 << " " << wi + 1 << endl;
      }
    }
  }
}
