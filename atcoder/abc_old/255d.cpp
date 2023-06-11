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
int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  vector<ll> max_ope_sum(n);
  rep(i, n) {
    ll max_ope = 1e9 - a[i];
    if (i == 0)
      max_ope_sum[i] = max_ope;
    else
      max_ope_sum[i] = max_ope_sum[i - 1] + max_ope;
  }

  vector<ll> min_ope_sum(n);
  rep(i, n) {
    ll min_ope = a[i];
    if (i == 0)
      min_ope_sum[i] = min_ope;
    else
      min_ope_sum[i] = min_ope_sum[i - 1] + min_ope;
  }

  rep(i, q) {
    ll x;
    cin >> x;
    ll top_begin_idx = upper_bound(a.begin(), a.end(), x) - a.begin();

    ll bottom_size = top_begin_idx;
    ll top_size = n - top_begin_idx;

    ll ans = 0;
    ans += min_ope_sum[n - 1] - min_ope_sum[top_begin_idx - 1];
    ans -= x * top_size;

    ans += max_ope_sum[top_begin_idx - 1];
    ans -= (1e9 - x) * bottom_size;

    cout << ans << endl;
  }
}