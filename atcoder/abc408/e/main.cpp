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

struct Path {
  int a, b, w;
};

bool comp(const Path &a, const Path &b) { return a.w > b.w; }

signed main() {
  int n, m;
  cin >> n >> m;

  vector<Path> path(m);
  rep(i, m) {
    Path p;
    cin >> p.a >> p.b >> p.w;
    p.a--;
    p.b--;
    path[i] = p;
  }

  int ac = (ll)1 << 30;
  int wa = 0;
  while (ac - wa != 1) {
    int wj = (ac + wa) / 2;

    dsu uf(n);
    for (auto p : path) {
      if (p.w <= wj) {
        uf.merge(p.a, p.b);
      }
    }

    if (uf.same(0, n - 1)) {
      ac = wj;
    } else {
      wa = wj;
    }
  }

  cout << ac << endl;
}