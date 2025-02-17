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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll SEARCH_MAX = 1e6 + 10;
  vector<int> A(SEARCH_MAX);
  rep(i, n) A[a[i]]++;

  // y=e[i]: iを約数に持つAはy個ある
  vector<int> e(SEARCH_MAX);
  for (ll i = 2; i <= SEARCH_MAX; i++) {
    int x = 0;
    for (ll j = i; j < SEARCH_MAX; j += i) {
      if (A[j] > 0) {
        x += A[j];
      }
    }
    e[i] = x;
  }

  rep(i, SEARCH_MAX) {
    if (e[i] < k) {
      // k個以上ないのであればノーカン
      e[i] = 0;
    } else {
      // k個以上あればiは答えの値である可能性がある
      e[i] = true;
    }
  }

  vector<int> ans(SEARCH_MAX);

  for (ll i = 2; i <= SEARCH_MAX; i++) {
    if (!e[i]) continue;
    for (ll j = i; j < SEARCH_MAX; j += i) {
      chmax(ans[j], i);
    }
  }

  rep(i, n) { cout << max(ans[a[i]], 1ll) << endl; }
}
