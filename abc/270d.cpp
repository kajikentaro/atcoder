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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep(i, k) cin >> a[i];

  int ans = 0;
  while (1) {
    {
      // Takahashi
      auto takahashi_itr = --upper_bound(a.begin(), a.end(), n);
      int takahashi = *takahashi_itr;
      ans += takahashi;
      n -= takahashi;
    }

    if (n == 0) break;

    {
      // Aoki
      auto aoki_itr = --upper_bound(a.begin(), a.end(), n);
      int aoki = *aoki_itr;
      n -= aoki;
    }

    if (n == 0) break;
  }

  cout << ans << endl;
}