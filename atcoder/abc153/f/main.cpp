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

// https://betrue12.hateblo.jp/entry/2020/09/23/005940#%E5%8C%BA%E9%96%93%E5%8A%A0%E7%AE%97%E5%8C%BA%E9%96%93%E6%9C%80%E5%A4%A7%E5%80%A4%E5%8F%96%E5%BE%97
using S = long long;
using F = long long;
const S INF = 8e18;
S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
using SegTree = lazy_segtree<S, op, e, F, mapping, composition, id>;

struct Monster {
  int h, x;
};

signed main() {
  int n, d, a;
  cin >> n >> d >> a;

  vector<Monster> mons(n);
  rep(i, n) {
    Monster mon;
    cin >> mon.x >> mon.h;
    mons[i] = mon;
  }

  sort(mons.begin(), mons.end(),
       [](const Monster &a, const Monster &b) { return a.x < b.x; });

  vector<int> seg_tmp(n);
  rep(i, n) seg_tmp[i] = mons[i].h;
  SegTree seg(seg_tmp);

  int ans = 0;
  rep(mi, n) {
    if (seg.get(mi) <= 0) continue;

    int left = mons[mi].x;
    int right = left + d * 2;

    auto itr = --upper_bound(
        mons.begin(), mons.end(), right,
        [](const int &val, const Monster &a) { return val < a.x; });
    int right_i = itr - mons.begin();
    int times = (seg.get(mi) + a - 1) / a;
    seg.apply(mi, min(right_i, n - 1) + 1, -a * times);
    ans += times;
  }
  cout << ans << endl;
}