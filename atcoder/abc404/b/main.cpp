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

vector<string> rotate(vector<string> in, int n) {
  vector<string> out = in;
  rep(i, n) rep(j, n) { out[i][j] = in[n - j - 1][i]; }
  return out;
}

signed main() {
  int n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<string> t(n);
  rep(i, n) cin >> t[i];

  int ans = 1e9;
  rep(ori, 4) {
    int tmp = ori;
    rep(i, n) rep(j, n) {
      if (s[i][j] != t[i][j]) tmp++;
    }
    chmin(ans, tmp);
    s = rotate(s, n);
  };

  cout << ans << endl;
}