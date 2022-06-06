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
int main() {
  int MOD = 1e9 + 7;
  int n;
  string s;
  cin >> n >> s;
  string atcoder = "atcoder";
  vector<ll> dp(atcoder.size());
  rep(i, n) {
    switch (s[i]) {
      case 'a':
        dp[0]++;
        break;
      case 't':
        dp[1] += dp[0];
        dp[1] %= MOD;
        break;
      case 'c':
        dp[2] += dp[1];
        dp[2] %= MOD;
        break;
      case 'o':
        dp[3] += dp[2];
        dp[3] %= MOD;
        break;
      case 'd':
        dp[4] += dp[3];
        dp[4] %= MOD;
        break;
      case 'e':
        dp[5] += dp[4];
        dp[5] %= MOD;
        break;
      case 'r':
        dp[6] += dp[5];
        dp[6] %= MOD;
        break;
    }
  }
  cout << dp[6] << endl;
}