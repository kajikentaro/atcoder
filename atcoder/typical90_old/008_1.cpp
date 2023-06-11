#include <bits/stdc++.h>
#define rep(x, y) for (int x = 0; x < y; x++)
#define ll long long
using namespace std;
int main() {
  int MOD = 1e9 + 7;
  int n;
  string s;
  cin >> n >> s;
  string atcoder = "atcoder";
  vector<vector<ll>> dp(n);
  dp[0] = vector<ll>(atcoder.size());
  if (s[0] == 'a') dp[0][0] = 1;
  rep(i, n) {
    if (i == 0) continue;
    dp[i] = dp[i - 1];
    switch (s[i]) {
      case 'a':
        dp[i][0]++;
        break;
      case 't':
        dp[i][1] += dp[i - 1][0];
        dp[i][1] %= MOD;
        break;
      case 'c':
        dp[i][2] += dp[i - 1][1];
        dp[i][2] %= MOD;
        break;
      case 'o':
        dp[i][3] += dp[i - 1][2];
        dp[i][3] %= MOD;
        break;
      case 'd':
        dp[i][4] += dp[i - 1][3];
        dp[i][4] %= MOD;
        break;
      case 'e':
        dp[i][5] += dp[i - 1][4];
        dp[i][5] %= MOD;
        break;
      case 'r':
        dp[i][6] += dp[i - 1][5];
        dp[i][6] %= MOD;
        break;
    }
  }
  cout << dp[n - 1][6] << endl;
}
