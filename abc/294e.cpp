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

struct Q {
  ll isBtm, length, pos_end, pos_start, value;
};

int main() {
  ll l, an, bn;
  cin >> l >> an >> bn;

  vector<Q> a(an);
  vector<Q> b(bn);
  ll tmp = 0;
  rep(i, an) {
    cin >> a[i].value >> a[i].length;
    a[i].pos_start = tmp;
    tmp += a[i].length;
    a[i].pos_end = tmp;
    a[i].isBtm = 0;
  }
  a.push_back(Q{(ll)0, 0, (ll)1e18, a[an - 1].pos_end, 0LL});
  tmp = 0;
  rep(i, bn) {
    cin >> b[i].value >> b[i].length;
    b[i].pos_start = tmp;
    tmp += b[i].length;
    b[i].pos_end = tmp;
    b[i].isBtm = 1;
  }
  b.push_back(Q{(ll)0, 0, (ll)1e18, b[bn - 1].pos_end, 0LL});

  int ai = 0, bi = 0;
  ll ans = 0;
  while (1) {
    if (ai == an && bi == bn) break;
    if (a[ai].pos_start > b[bi].pos_start) {
      swap(a, b);
      swap(ai, bi);
      swap(an, bn);
    }

    if (bi > 0 && a[ai].value == b[bi - 1].value) {
      ll length = min(a[ai].pos_end, b[bi - 1].pos_end) -
                  max(a[ai].pos_start, b[bi - 1].pos_start);
      ans += length;
    }
    ai++;
  }

  cout << ans << endl;
}