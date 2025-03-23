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
  int n, r, c;
  cin >> n >> r >> c;
  string s;
  cin >> s;

  int dx = 0;
  int dy = 0;

  vector<int> ans;
  map<P, bool> ma;
  rep(i, n + 1) {
    ma[P{dx, dy}] = true;
    if (ma[P{dx + r, dy + c}]) {
      ans.push_back(1);
    } else {
      ans.push_back(0);
    }

    switch (s[i]) {
      case 'N':
        dx++;
        break;
      case 'S':
        dx--;
        break;
      case 'E':
        dy--;
        break;
      case 'W':
        dy++;
        break;
    };
  };

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;
}