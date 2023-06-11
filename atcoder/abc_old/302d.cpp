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
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n);
  vector<int> b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = -1;
  rep(i, n) {
    int ac = 0;
    int wa = m;
    while (wa - ac != 1) {
      int wj = (ac + wa) / 2;
      int target = a[i] + d;
      if (b[wj] <= target) {
        ac = wj;
      } else {
        wa = wj;
      }
    }

    if (abs(a[i] - b[ac]) > d) continue;
    chmax(ans, a[i] + b[ac]);
  }
  cout << ans << endl;
  ;
}