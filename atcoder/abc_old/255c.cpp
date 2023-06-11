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
ll func() {
  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  if (d == 0) return abs(x - a);

  ll s_last = a + d * (n - 1);

  ll s_min = min(a, s_last);
  ll s_max = max(a, s_last);
  if (x < s_min) return s_min - x;
  if (s_max < x) return x - s_max;

  // 視点を0からに
  if (d < 0) d *= -1;
  x -= s_min;
  ll dist = x % d;
  ll ans = min(dist, d - dist);
  return ans;
}
int main() { cout << func() << endl; }