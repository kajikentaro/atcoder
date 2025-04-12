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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2);

  vector<vector<int>> val_to_idx(n);
  rep(i, n * 2) {
    cin >> a[i];
    a[i]--;

    assert(a[i] < n);
    val_to_idx[a[i]].push_back(i);
  }

  rep(i, n) { sort(val_to_idx[i].begin(), val_to_idx[i].end()); }

  map<P, bool> used;

  auto is_next = [&](vector<int> &idx_list) {
    assert(idx_list.size() == 2);
    if (abs(idx_list[0] - idx_list[1]) == 1) return true;
    return false;
  };

  int ans = 0;
  rep(i, n * 2 - 1) {
    int val_1 = a[i];
    int val_2 = a[i + 1];
    assert(val_1 < n);
    assert(val_2 < n);
    if (used[P{val_1, val_2}]) continue;

    auto val_1_idx = val_to_idx[val_1];
    auto val_2_idx = val_to_idx[val_2];

    if (is_next(val_1_idx)) {
      continue;
    }
    if (is_next(val_2_idx)) {
      continue;
    }

    vector<int> others = {val_1_idx[1], val_2_idx[1]};
    if (is_next(others)) {
      ans++;
    }

    used[P{val_1, val_2}] = 1;
    used[P{val_2, val_1}] = 1;
  }

  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  rep(i, t) solve();
}