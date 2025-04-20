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
  int n, a_size;
  cin >> n >> a_size;

  vector<vector<int>> g_to_ai(n + 10);
  vector<int> a_hate_count(a_size);

  rep(ai, a_size) {
    int k;
    cin >> k;
    rep(j, k) {
      // 食材g
      int g;
      cin >> g;
      g_to_ai[g].push_back(ai);
    }
    a_hate_count[ai] = k;
  }

  int ans = 0;
  for (auto can : a_hate_count) {
    if (can == 0) ans++;
  }

  rep(i, n) {
    int g;
    cin >> g;

    for (auto ai : g_to_ai[g]) {
      a_hate_count[ai]--;
      if (a_hate_count[ai] == 0) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}