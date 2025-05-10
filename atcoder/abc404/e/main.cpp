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
  vector<int> c(n);
  orep(i, n - 1) cin >> c[i];

  vector<int> a(n);
  orep(i, n - 1) cin >> a[i];

  set<int> used;
  vector<vector<int>> path(n);
  rep(i, n) {
    if (i == 0) continue;

    int begin = i - c[i];
    int end = i;
    if (begin == 0) {
      path[i].push_back(i);
    } else {
      int mi_cnt = 1e9;
      int mi_idx = -1;
      for (int j = begin; j < end; j++) {
        if (chmin(mi_cnt, (int)path[j].size())) {
          mi_idx = j;
        };
      }
      path[i] = path[mi_idx];
      path[i].push_back(i);
    }

    if (a[i] == 0) continue;
    for (auto p : path[i]) {
      used.insert(p);
      path[p].resize(0);
    }
  }

  cout << used.size() << endl;
}