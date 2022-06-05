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
  while (1) {
    vector<int> a(4);
    rep(i, 4) cin >> a[i];

    if (*max_element(a.begin(), a.end()) == 0) break;
    while (1) {
      int mi = 1e9;
      int mi_idx = -1;
      rep(i, 4) {
        if (a[i] == 0) continue;
        if (chmin(mi, a[i])) {
          mi_idx = i;
        }
      }
      bool operation = false;
      rep(i, 4) {
        if (i == mi_idx) continue;
        if (a[i] == 0) continue;
        operation = true;
        a[i] -= mi;
      }
      if (operation) continue;
      cout << mi << endl;
      break;
    }
  }
}