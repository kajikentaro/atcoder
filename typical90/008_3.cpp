#include <bits/stdc++.h>
#define rep(x, y) for (int x = 0; x < y; x++)
#define ll long long
using namespace std;
int main() {
  int n, MOD = 1e9 + 7;
  string s;
  cin >> n >> s;
  string atcoder = "atcoder";
  vector<ll> dp(atcoder.size());
  rep(i, n) {
    rep(j, atcoder.size()) {
      if (s[i] == 'a') {
        dp[0]++;
        break;
      }
      if (s[i] == atcoder[j]) {
        dp[j] += dp[j - 1];
        dp[j] %= MOD;
      }
    }
  }
  cout << dp[6] << endl;
}