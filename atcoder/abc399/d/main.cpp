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
  vector<int> a(2 * n);
  vector<vector<int>> val_to_idx(n);
  rep(i, 2 * n) {
    cin >> a[i];

    a[i]--;
    val_to_idx[a[i]].push_back(i);
  }

  vector<P> can;
  rep(i, 2 * n - 1) {
    int val_1 = a[i];
    int val_2 = a[i + 1];

    if (val_1 > val_2) swap(val_1, val_2);  // val_1 is smaller
    can.emplace_back(val_1, val_2);
  }

  sort(can.begin(), can.end());
  can.erase(unique(can.begin(), can.end()), can.end());

  auto is_next = [&](vector<int> idx_list) {
    if (abs(idx_list[0] - idx_list[1]) == 1) {
      return true;
    }
    return false;
  };

  int ans = 0;
  for (auto [val_1, val_2] : can) {
    auto val_1_idx = val_to_idx[val_1];
    auto val_2_idx = val_to_idx[val_2];

    if (is_next(val_1_idx)) continue;
    if (is_next(val_2_idx)) continue;

    sort(val_1_idx.begin(), val_1_idx.end());
    sort(val_2_idx.begin(), val_2_idx.end());

    vector<int> first = {val_1_idx[0], val_2_idx[0]};
    vector<int> second = {val_1_idx[1], val_2_idx[1]};

    if (!is_next(first)) continue;
    if (!is_next(second)) continue;

    ans++;
  }

  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  ;
}