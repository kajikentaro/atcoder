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
using mint = modint998244353;
using P = pair<int, int>;
ll exec_dp(int n, string s) {
  // dp[桁][is_strict] = 場合の数
  vector<vector<mint>> dp(n, vector<mint>(2));
  rep(i, n) {
    mint loose_case = s[i] - 'A';
    if (i == 0) {
      dp[0][0] = loose_case;
      dp[0][1] = 1;
      continue;
    }
    dp[i][0] += dp[i - 1][0] * 26;
    dp[i][0] += dp[i - 1][1] * loose_case;

    dp[i][1] += dp[i - 1][1];
  }
  mint ans = dp[n - 1][0] + dp[n - 1][1];
  return ans.val();
}
void func() {
  int n;
  string s;
  cin >> n >> s;
  string reverse_s = "";
  rrep(i, n) reverse_s += s[i];

  string center_to_start = "";
  string center_to_last = "";

  int center_len = (n + 1) / 2;
  int center_idx = center_len - 1;
  rep(i, center_len) {
    center_to_start += s[center_idx - i];
    center_to_last += s[center_idx + i];
  }

  ll ans;
  if (center_to_start < center_to_last) {
    ans = exec_dp(center_len, s);
  } else {
    ans = exec_dp(center_len, reverse_s);
  }

  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  rep(i, t) func();
}