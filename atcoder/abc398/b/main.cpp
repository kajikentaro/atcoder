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
  int n = 7;
  map<int, int> ma;
  rep(i, n) {
    int a;
    cin >> a;
    ma[a]++;
  }

  int n3 = 0;
  int n2 = 0;
  for (auto [kind, cnt] : ma) {
    if (cnt >= 3) n3++;
    if (cnt >= 2) n2++;
  }

  if (n2 >= 2 && n3 >= 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  };
}