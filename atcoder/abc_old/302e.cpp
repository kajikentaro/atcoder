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
  int n, q;
  cin >> n >> q;

  int ans = n;
  vector<set<int>> path(n);
  rep(_, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      if (path[a].size() == 0) ans--;
      if (path[b].size() == 0) ans--;
      path[a].insert(b);
      path[b].insert(a);
    }
    if (t == 2) {
      int a;
      cin >> a;
      a--;
      if (path[a].size() >= 1) ans++;
      for (auto next : path[a]) {
        path[next].erase(a);
        if (path[next].size() == 0) ans++;
      }
      path[a].clear();
    }
    cout << ans << endl;
  };
}