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
int main() {
  vector<int> h(3);
  vector<int> w(3);
  rep(i, 3) cin >> h[i];
  rep(i, 3) cin >> w[i];

  ll ans = 0;
  orep(a, 28) orep(b, 28) orep(c, 28) orep(d, 28) {
    int e = h[0] - a - b;
    int f = h[1] - c - d;
    int g = w[0] - a - c;
    int h_ = w[1] - b - d;

    if (e <= 0) continue;
    if (f <= 0) continue;
    if (g <= 0) continue;
    if (h_ <= 0) continue;

    int g_1 = w[2] - e - f;
    int g_2 = h[2] - g - h_;

    if (g_1 <= 0) continue;
    if (g_2 <= 0) continue;

    if (g_1 == g_2) {
      ans++;
    }
  }
  cout << ans << endl;
}