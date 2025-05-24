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
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  vector<int> type(n);
  rep(i, n) {
    int j = i + 1;
    int k = i + 2;
    if (k >= n) {
      break;
    }

    if (p[i] < p[j] && p[j] > p[k]) {
      type[j] = 1;
    }
    if (p[i] > p[j] && p[j] < p[k]) {
      type[j] = 2;
    }
  }

  ll ans = 0;
  vector<int> dp(4);
  rep(i, n) {
    ans += dp[3];
    if (type[i] == 0) {
      dp[0]++;
      continue;
    }
    if (type[i] == 1) {
      // dp[3] = dp[2];
      dp[3] = 0;
      dp[2] = 0;
      dp[1] = dp[0];
      dp[0] = 1;
      continue;
    }
    if (type[i] == 2) {
      dp[3] = dp[1];
      dp[1] = 0;
      dp[2] = dp[0];
      dp[0] = 1;
    }
  }
  cout << ans << endl;
};