#include <bits/stdc++.h>

#include <atcoder/all>
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
bool split_linear(ll x, ll y, ll a, ll b, ll c) {
  ll y_now = 0;
  y_now += (a + x - 1) / x;
  y_now += (b + x - 1) / x;
  y_now += (c + x - 1) / x;
  if (y_now <= y) return true;
  return false;
}
bool split_window(ll x, ll y, ll a, ll b, ll c) {
  ll a_x = (a + y - 1) / y;

  x -= a_x;
  if (x <= 0) return false;

  ll y_now = 0;
  y_now += (b + x - 1) / x;
  y_now += (c + x - 1) / x;

  if (y_now <= y) return true;
  return false;
}
int func() {
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  if (x * y < a + b + c) return false;

  bool flag = false;
  flag |= split_linear(x, y, a, b, c);
  flag |= split_linear(y, x, a, b, c);

  flag |= split_window(x, y, a, b, c);
  flag |= split_window(x, y, b, c, a);
  flag |= split_window(x, y, c, a, b);

  flag |= split_window(y, x, a, b, c);
  flag |= split_window(y, x, b, c, a);
  flag |= split_window(y, x, c, a, b);
  return flag;
}
int main() {
  if (func()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}