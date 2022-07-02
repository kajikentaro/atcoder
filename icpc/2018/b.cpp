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
bool func() {
  int h, w, t, p;
  cin >> w >> h >> t >> p;
  if (w + h + t + p == 0) return false;

  vector<vector<int>> dp(h, vector<int>(w, 1));

  // fold step
  rep(i, t) {
    int type, c;
    cin >> type >> c;
    if (type == 1) {
      vector<vector<int>> new_dp(h, vector<int>(w - c));
      rep(hi, h) rep(wi, w) {
        int new_hi = hi;
        int new_wi;
        if (wi <= c - 1) {
          new_wi = c - wi - 1;
        } else {
          new_wi = wi - c;
        }
        new_dp[new_hi][new_wi] += dp[hi][wi];
      }
      h = h;
      w = w - c;
      swap(dp, new_dp);
    }
    if (type == 2) {
      vector<vector<int>> new_dp(h - c, vector<int>(w));
      rep(hi, h) rep(wi, w) {
        int new_hi;
        if (hi <= c - 1) {
          new_hi = c - hi - 1;
        } else {
          new_hi = hi - c;
        }
        int new_wi = wi;
        new_dp[new_hi][new_wi] += dp[hi][wi];
      }
      h = h - c;
      w = w;
      swap(dp, new_dp);
    }
  }

  rep(i, p) {
    int hi, wi;
    cin >> hi >> wi;
  }
}
int main() {
  while (func()) {
    ;
  }
}