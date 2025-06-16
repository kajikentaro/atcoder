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

bool solve() {
  int r, x;
  cin >> r >> x;
  if (x == 1) {
    if (1600 <= r && r <= 2999) {
      return true;
    }
    return false;
  }

  if (x == 2) {
    if (1200 <= r && r <= 2399) {
      return true;
    }
    return false;
  };
}

signed main() {
  if (solve()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}