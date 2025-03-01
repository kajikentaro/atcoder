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

int op(int a, int b) { return max(a, b); }

int e() { return 0; }

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> dp(n);
  {
    segtree<int, op, e> seg(n + 1);
    rep(i, n) {
      // dp[i] = 0-a[i]の区間のmax(f())
      int max_label = seg.prod(0, a[i]);
      seg.set(a[i], max_label + 1);
      dp[i] = max_label + 1;
    };
  }
  vector<int> rdp(n);
  {
    segtree<int, op, e> seg(n + 1);
    rrep(i, n) {
      // dp[i] = 0-a[i]の区間のmax(f())
      int max_label = seg.prod(0, a[i]);
      seg.set(a[i], max_label + 1);
      rdp[i] = max_label + 1;
    };
  }

  int ans = 0;
  rep(i, n) {
    int res = dp[i] + rdp[i] - 1;
    chmax(ans, res);
  }
  cout << ans << endl;
}