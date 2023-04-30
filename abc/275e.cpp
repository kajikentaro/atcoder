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

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<mint> dp(n + 1);
  dp[0] = 1;

  rep(_, k) {
    vector<mint> dp_old(n + 1);
    swap(dp_old, dp);

    dp[n] = dp_old[n] * m;
    rep(i, n) {
      orep(j, m) {
        int next = i + j <= n ? i + j : 2 * n - i - j;
        dp[next] += dp_old[i];
      }
    }
  }

  mint sum = 0;
  rep(i, n + 1) sum += dp[i];
  mint success = dp[n];

  mint ans = success / sum;

  cout << ans.val() << endl;
}