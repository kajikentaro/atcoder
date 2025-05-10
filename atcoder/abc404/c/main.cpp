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

bool solve() {
  int n, m;
  cin >> n >> m;

  vector<P> input(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    input[i].first = a;
    input[i].second = b;
  }

  {
    if (n != m) return false;
  }

  {
    dsu uf(n);
    rep(i, m) { uf.merge(input[i].first, input[i].second); }
    auto res = uf.groups();
    if (res.size() != 1) return false;
  }

  {
    vector<int> degs(n);
    rep(i, m) {
      degs[input[i].first]++;
      degs[input[i].second]++;
    }

    for (auto d : degs) {
      if (d != 2) return false;
    }
  }
  return true;
}

signed main() {
  bool is_sycle = solve();
  if (is_sycle) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}