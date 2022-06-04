#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
int main() {
  ll k;
  ll mod = (ll)1e9 + 7;
  cin >> k;
  vector<ll> dp(k + 20);
  dp[0] = 1;
  if (k % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, k + 10) {
    orep(j, 9) { dp[i + j] = (dp[i + j] + dp[i]) % mod; }
  }
  cout << dp[k] << endl;
}