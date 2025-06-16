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

ll solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  n++;
  s += '0';

  int a = 0;
  int b = 0;
  int c = 1e9;

  for (auto ss : s) {
    if (ss == '1') {
      a++;
    }

    if (ss == '0') {
      b++;
    }

    if (b > a) b = a;

    if (ss == '0' && c == (int)1e9) {
      c = 0;
    }

    if (ss == '1') {
      c++;
    }

    if (c > b) {
      c = b;
    }
  }

  return c;
}

signed main() {
  int t;
  cin >> t;
  rep(i, t) cout << solve() << endl;
  ;
}