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
  int n, m, q;
  cin >> n >> m >> q;

  map<int, bool> allok;
  map<int, set<int>> permissions;
  rep(i, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      permissions[x].insert(y);
    }
    if (type == 2) {
      int x;
      cin >> x;
      allok[x] = true;
    }
    if (type == 3) {
      int x, y;
      cin >> x >> y;
      if (allok[x]) {
        cout << "Yes" << endl;
        continue;
      }
      if (permissions[x].count(y)) {
        cout << "Yes" << endl;
        continue;
      }
      cout << "No" << endl;
    }
  };
}