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

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;
      string now = s[i] + s[j];

      bool isOk = true;
      rep(k, now.size()) {
        if (k >= now.size() - 1 - k) break;
        if (now[k] == now[now.size() - 1 - k]) continue;
        isOk = false;
      }
      if (isOk) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
