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
  int a, b;
  cin >> a >> b;

  double a1 = a / b;
  double a2 = (a + b - 1) / b;

  auto t1 = abs((double)a / b - a1);
  auto t2 = abs((double)a / b - a2);

  if (t1 < t2) {
    cout << a1 << endl;
  } else {
    cout << a2 << endl;
  }

  ;
}