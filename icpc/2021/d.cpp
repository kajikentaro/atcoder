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
bool func() {
  int n;
  cin >> n;
  if (n == 0) return false;
  vector<int> b(n);
  rep(i, n) cin >> b[i];

  // dp[個数[2510]][個数(2510)] = 数(1)
  vector<vector<int>> dp(2510, vector<int>(2510));
  dp[0][0] = 1;
  int sum = 0;
  rep(bi, n) {
    sum += b[bi];
    rrep(i, 2505) rrep(j, 2505) {
      // 高速化できそう
      if (dp[i][j] == 0) continue;

      int A = i + b[bi];
      if (A <= 2505) {
        dp[A][j] = 1;
      }

      int B = j + b[bi];
      if (B <= 2505) {
        dp[i][B] = 1;
      }
    }
  }

  int ans = 0;
  rep(i, 2505) rep(j, 2505) {
    if (dp[i][j] == 0) continue;
    int k = sum - i - j;
    int small_ans = min(min(i, j), k);
    chmax(ans, small_ans);
  }
  cout << ans << endl;
  return true;
}
int main() {
  while (func()) {
  }
}