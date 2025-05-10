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
  string s;
  cin >> s;
  int n = s.size();

  vector<int> a(100);
  rep(i, n) { a[s[i] - 'a'] = 1; }

  rep(i, 26) {
    if (a[i] == 1) continue;
    char ans = i + 'a';
    cout << ans << endl;
    return 0;
  }
}