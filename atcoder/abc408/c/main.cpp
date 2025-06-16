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
  int n, m;
  cin >> n >> m;

  vector<int> h(n + 2);
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    h[l]++;
    h[r + 1]--;
  };

  int mi = 1e9;

  int now = 0;
  rep(i, n + 1) {
    if (i == 0) continue;
    now += h[i];
    chmin(mi, now);
  }

  cout << mi << endl;
}