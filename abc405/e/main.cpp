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

map<P, int> memo;
ll comb(int n, int r) {
  if (memo.count(P(n, r))) {
    return memo[P(n, r)];
  }
  ll i = 1;
  ll k = r > n - r ? n - r : r, count;
  if (k < 0) return 0;
  std::list<ll> list;
  std::list<ll>::iterator it;
  for (count = 2; count <= k; ++count) list.push_back(count);
  for (count = n; count > n - k; --count) {
    i *= count;
    for (it = list.begin(); it != list.end();) {
      if (!(i % *it)) {
        i /= *it;
        it = list.erase(it);
      } else
        ++it;
    }
  }
  memo[P(n, r)] = i;
  return i;
}

signed main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n = a + b + c + d;

  for (int i = a + 1; i <= (n - c); i++) {
    int used_b = i - 1 - a;
    for (int j = i + used_b; j <= n - d; j++) {
    }
  };
}