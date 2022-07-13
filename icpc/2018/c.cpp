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
ll calc(ll n, ll b) {
  if (b * 2 % n) return 0;
  ll eq1 = (b * 2) / n;

  ll eq2 = eq1 - n + 1;

  if (eq2 % 2) return 0;
  ll a = eq2 / 2;

  if (a > 0) return a;
  return 0;
}
bool func() {
  ll b;
  cin >> b;
  if (b == 0) return false;

  int ans_a = 0;
  int ans_n = 0;
  orep(i, 2 * (int)sqrt(b) + 1) {
    ll a = calc(i, b);
    if (a && chmax(ans_n, i)) {
      ans_a = a;
      ans_n = i;
    }
  }
  if (ans_a) {
    cout << ans_a << " " << ans_n << endl;
  } else {
    cout << b << " " << 1 << endl;
  }
  return true;
}
int main() {
  while (func()) {
    ;
  }
}