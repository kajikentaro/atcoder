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
  string t, u;
  cin >> t >> u;

  int tn = t.size();
  int un = u.size();
  int diff = tn - un + 1;
  rep(ti, diff) {
    string tt = t.substr(ti, un);
    bool isok = true;
    rep(i, un) {
      if (tt[i] == '?') continue;
      if (tt[i] != u[i]) isok = false;
    }
    if (isok) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  ;
}