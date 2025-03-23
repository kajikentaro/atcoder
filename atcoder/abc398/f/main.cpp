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

  string t = s;
  reverse(t.begin(), t.end());
  t += s;

  auto z = z_algorithm(t);

  rep(i1, n) {
    int i2 = i1 + n;
    if (z[i2] == n - i1) {
      cout << s;
      rep(j, i1) { cout << s[i1 - j - 1]; }
      cout << endl;
      break;
    }
  }
}