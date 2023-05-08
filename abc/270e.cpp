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

struct Boundary {
  ll num;
  ll dist;
};

signed main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<Boundary> boundary;
  {
    map<int, int> ma;
    rep(i, n) ma[a[i]]++;

    int now = n;
    int pre_dist = 0;
    for (auto m : ma) {
      Boundary b;
      b.num = now;
      b.dist = m.first - pre_dist;
      pre_dist = m.first;
      boundary.push_back(b);
      now -= m.second;
    }
  }

  int round_sum = 0;
  for (auto b : boundary) {
    int round = (k + b.num - 1) / b.num;
    if (round <= b.dist) {
      round_sum += round - 1;
      rep(i, n) { a[i] = max(a[i] - round_sum, 0LL); }
      rep(i, n) {
        if (k == 0) break;
        if (a[i] > 0) {
          a[i]--;
          k--;
        }
      }
      rep(i, n) { cout << a[i] << " "; }
      cout << endl;
      return 0;
    } else {
      round_sum += b.dist;
      k -= b.dist * b.num;
    }
  }
}