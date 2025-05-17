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
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  auto check = [&]() {
    set<int> se;
    for (auto aa : a) {
      if (aa <= m) se.insert(aa);
    }

    if (se.size() == m) {
      return true;
    }
    return false;
  };

  int ans = 0;
  while (true) {
    if (!check()) {
      cout << ans << endl;
      return 0;
    }
    a.pop_back();
    ans++;
  }
}