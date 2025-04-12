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

  vector<vector<int>> used(n, vector<int>(n));

  rep(i, 2 * n) {
    cin >> a[i];
    a[i]--;
    val_to_idx[a[i]].push_back(i);
  }

  auto already_ok = [&](int idx) {
    int now_val = a[idx];

    if (idx + 1 <= n - 1) {
      int right_val = a[idx + 1];
      if (now_val == right_val) {
        return true;
      }
    }

    if (idx - 1 >= 0) {
      int left_val = a[idx - 1];
      if (now_val == left_val) {
        return true;
      }
    }

    return false;
  };

  int ans = 0;
  rep(i, 2 * n - 1) {
    int val_1 = a[i];
    int val_2 = a[i + 1];

    if (val_1 == val_2) continue;

    vector<int> val_1_idx = val_to_idx[val_1];
    vector<int> val_2_idx = val_to_idx[val_2];

    sort(val_1_idx.begin(), val_1_idx.end());
    sort(val_2_idx.begin(), val_2_idx.end());

    if (already_ok(val_1_idx[0])) continue;
    if (already_ok(val_1_idx[1])) continue;
    if (already_ok(val_2_idx[0])) continue;
    if (already_ok(val_2_idx[1])) continue;

    if (used[val_1][val_2]) {
      continue;
    }

    if (abs(val_1_idx[0] - val_2_idx[0]) == 1 &&
        abs(val_1_idx[1] - val_2_idx[1])) {
      ans++;

      used[val_1][val_2] = 1;
      used[val_2][val_1] = 1;
    }

    // a[val_1_idx_1] = val_1;
    // a[val_2_idx_1] = val_1;
    // a[val_1_idx_2] = val_2;
    // a[val_2_idx_2] = val_2;

    // val_to_idx_2[val_1] = val_2_idx_1;
    // val_to_idx_2[val_2] = val_2_idx_2;

    // i++;
  }

  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  ;
}