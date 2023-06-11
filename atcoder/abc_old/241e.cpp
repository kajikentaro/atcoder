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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<int> a_idx(n, -1);
  rep(i, n) cin >> a[i];

  vector<ll> b;
  ll sum_mod = 0;
  ll sum = 0;

  ll loop_start = -1;
  rep(i, k) {
    if (a_idx[sum_mod] != -1) {
      loop_start = a_idx[sum_mod];
      break;
    }
    a_idx[sum_mod] = i;
    b.push_back(a[sum_mod]);
    sum += a[sum_mod];
    sum_mod = sum % n;
  }
  if (loop_start == -1) {
    cout << sum << endl;
    return 0;
  }

  ll loop_size = b.size() - loop_start;
  ll loop_sum = 0;
  for (ll i = loop_start; i < b.size(); i++) {
    loop_sum += b[i];
  }

  ll loop_n = (k - loop_start) / loop_size;
  ll loop_surplus = (k - loop_start) % loop_size;

  ll ans = loop_n * loop_sum;
  for (ll i = 0; i < loop_start + loop_surplus; i++) {
    ans += b[i];
  }
  cout << ans << endl;
}