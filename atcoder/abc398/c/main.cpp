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
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> ma;
  rep(i, n) {
    cin >> a[i];
    ma[a[i]]++;
  }

  int ans_val = -1;
  int ans_idx = -1;
  rep(i, n) {
    if (ma[a[i]] == 1) {
      bool changed = chmax(ans_val, a[i]);
      if (changed) {
        ans_idx = i;
      }
    }
  }

  if (ans_idx == -1) {
    cout << -1 << endl;
  } else {
    cout << ans_idx + 1 << endl;
  };
}