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
  vector<ll> sum(n);
  rep(i, n) cin >> a[i];
  rep(i, n) {
    if (i == 0) continue;
    if (i % 2 == 0) {
      int now_sleep = a[i] - a[i - 1];
      sum[i] = sum[i - 1] + now_sleep;
      if (i + 1 <= n - 1) sum[i + 1] = sum[i];
    }
  }

  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    auto itr_l = lower_bound(a.begin(), a.end(), l);
    auto itr_r = --upper_bound(a.begin(), a.end(), r);
    int val_l = *itr_l;
    int val_r = *itr_r;
    int idx_l = itr_l - a.begin();
    int idx_r = itr_r - a.begin();

    int start;
    if (idx_l % 2 == 0) {
      // wake up
      start = sum[idx_l] - (val_l - l);
    } else {
      // sleep
      start = sum[idx_l];
    }

    int end;
    if (idx_r % 2 == 0) {
      // wake up
      end = sum[idx_r];
    } else {
      // sleep
      end = sum[idx_r] + (r - val_r);
    }

    int res = end - start;
    cout << res << endl;
  };
}
