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
  int width;
  ll height;
};

signed main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<Boundary> boundary;
  {
    // map[height] = count
    map<ll, ll> ma;
    rep(i, n) { ma[a[i]]++; }

    int pre_width = n;
    int pre_height = 0;
    for (auto m : ma) {
      int h = m.first;
      int w = m.second;

      Boundary b;
      b.width = pre_width;
      b.height = h - pre_height;
      boundary.push_back(b);

      pre_height = h;
      pre_width -= w;
    }
  }

  ll sum_height = 0;
  for (auto b : boundary) {
    ll round_up = (k + b.width - 1) / b.width;
    if (round_up > b.height) {
      sum_height += b.height;
      k -= b.height * b.width;
      continue;
    }

    int inner_height = k / b.width;
    k -= b.width * inner_height;
    sum_height += inner_height;

    rep(i, n) {
      a[i] -= sum_height;
      chmax(a[i], 0LL);
    }

    rep(i, n) {
      if (k == 0) break;
      if (a[i] > 0) {
        a[i]--;
        k--;
      }
    }
    assert(k == 0);

    rep(i, n) cout << a[i] << " ";
    cout << endl;
    return 0;
  }
  assert(true);
}
