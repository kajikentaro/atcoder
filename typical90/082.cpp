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
int keta(mint a) {
  string b = to_string(a.val());
  return b.size();
}
mint keta_pow(int keta) {
  mint a = 1;
  rep(i, keta) { a *= 10; }
  return a;
}
int main() {
  ll a, b;
  cin >> a >> b;
  mint l = a;
  mint r = b;

  mint ans = 0;
  for (int i = keta(l); i <= keta(r); i++) {
    mint mi = i == keta(l) ? l : keta_pow(i - 1);
    mint ma = i == keta(r) ? r : keta_pow(i) - 1;
    mint n = ma - mi + 1;
    ans += (mi + ma) * n / 2 * i;
  }
  cout << ans.val() << endl;
}