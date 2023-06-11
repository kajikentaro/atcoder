#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<vector<int>> s2(n, vector<int>(10));
  rep(i, n) rep(j, 10) s2[i][s[i][j] - '0'] = j;
  int ans = 1e9;
  rep(number, 10) {
    vector<int> tmp(10);
    rep(i, n) { tmp[s2[i][number]]++; }
    int tmp2 = 0;
    int res;
    rep(i, 10) {
      tmp2 += tmp[i];
      if (tmp2 == n) {
        res = i;
        break;
      }
    }
    rep(i, 10) { res += max(tmp[i] - 1, 0) * 10; }
    chmin(ans, res);
  }
  cout << ans << endl;
}