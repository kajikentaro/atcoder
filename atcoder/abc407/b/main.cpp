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
  int x, y;
  cin >> x >> y;

  auto is_ok = [&](int a, int b) {
    int su = a + b;
    if (su >= x) {
      return true;
    }

    int ab = abs(a - b);
    if (ab >= y) {
      return true;
    }
    return false;
  };

  int cnt = 0;
  orep(i, 6) orep(j, 6) {
    if (is_ok(i, j)) cnt++;
  }

  printf("%.20lf\n", (double)cnt / 36);
}