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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> sum(n);
  rep(i, n) {
    if (i == 0) continue;
    if (i % 2) {
      // sleep
      sum[i] = sum[i - 1];
    } else {
      // wake up
      sum[i] = sum[i - 1] + a[i] - a[i - 1];
    }
  }

  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;

    auto calc = [&](int search) {
      int res;
      auto idx = --upper_bound(a.begin(), a.end(), search) - a.begin();
      if (idx % 2) {
        // sleep
        res = sum[idx] + (search - a[idx]);
      } else {
        // wake up
        res = sum[idx];
      }
      return res;
    };

    int rans = calc(r);
    int lans = calc(l);
    int ans = rans - lans;
    cout << ans << endl;
  }
}