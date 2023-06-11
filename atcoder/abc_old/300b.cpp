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
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  vector<string> b(h);

  rep(i, h) cin >> a[i];
  rep(i, h) cin >> b[i];

  rep(i, h) rep(j, w) {
    bool isOk = true;
    rep(hi, h) rep(wi, w) {
      if (a[hi][wi] != b[(hi + i) % h][(wi + j) % w]) isOk = false;
    }
    if (isOk) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}