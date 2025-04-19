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
  int n;
  cin >> n;

  bool is_login = false;
  int ans = 0;
  rep(i, n) {
    string s;
    cin >> s;
    if (s == "login") {
      is_login = true;
    }
    if (s == "logout") {
      is_login = false;
    }
    if (s == "public") {
    }
    if (s == "private") {
      if (is_login) {
      } else {
        ans++;
      }
    }
  };

  cout << ans << endl;
}