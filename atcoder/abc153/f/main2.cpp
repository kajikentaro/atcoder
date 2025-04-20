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

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

struct Monster {
  int x, h;
};

// abc153f
signed main() {
  int n, d, a;
  cin >> n >> d >> a;

  vector<Monster> monsters;

  rep(i, n) {
    int x, h;
    cin >> x >> h;

    Monster m;
    m.h = (h + a - 1) / a;
    m.x = x;
    monsters.push_back(m);
  }

  auto comp = [](const Monster &a, const Monster &b) { return a.x < b.x; };
  sort(monsters.begin(), monsters.end(), comp);

  // https://betrue12.hateblo.jp/entry/2020/09/23/005940#%E5%8C%BA%E9%96%93%E5%8A%A0%E7%AE%97%E5%8C%BA%E9%96%93%E6%9C%80%E5%A4%A7%E5%80%A4%E5%8F%96%E5%BE%97
  vector<S> v(n);
  rep(i, n) { v[i] = monsters[i].h; }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  int ans = 0;
  int left_most_idx = 0;
  while (left_most_idx < n) {
    int h = seg.get(left_most_idx);
    if (h <= 0) {
      left_most_idx++;
      continue;
    }

    int x_right = monsters[left_most_idx].x + d * 2;
    auto comp2 = [](const int &val, const Monster &a) { return val < a.x; };
    auto itr = --upper_bound(monsters.begin(), monsters.end(), x_right, comp2);
    int x_right_idx = itr - monsters.begin();

    // 例えば 1~3の3つの要素に7を加算したいときは、seg.apply(1, 4, 7);
    seg.apply(left_most_idx, x_right_idx + 1, -h);
    ans += h;

    left_most_idx++;
  }

  cout << ans << endl;
}