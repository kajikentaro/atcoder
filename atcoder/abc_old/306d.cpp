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

// dp[0] good shape
// dp[1] bad shape
signed main() {
  int n;
  cin >> n;

  vector<int> dp(2);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    vector<int> dp_old = dp;
    swap(dp, dp_old);
    if (x == 0) {
      chmax(dp[0], dp_old[0] + y);
      chmax(dp[0], dp_old[1] + y);
    } else {
      chmax(dp[1], dp_old[0] + y);
    }
  };
  cout << max(dp[0], dp[1]) << endl;
}