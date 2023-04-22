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

void do_dp(int n, vector<vector<mint>> &dp, int dice_max) {
  for (int turn = 1; turn <= n; turn++) {
    for (int pos = 0; pos < n; pos++) {
      for (int dice = 1; dice <= dice_max; dice++) {
        dp[turn][min(pos + dice, n)] += dp[turn - 1][pos] / dice_max;
      }
    }
  }
}

int main() {
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;

  vector<vector<mint>> a_dp(n + 1, vector<mint>(n + 1));
  vector<vector<mint>> b_dp(n + 1, vector<mint>(n + 1));
  a_dp[0][a] = 1;
  b_dp[0][b] = 1;

  do_dp(n, a_dp, p);
  do_dp(n, b_dp, q);

  mint ans = 0;
  rep(ai, n + 1) rep(bi, n + 1) {
    if (ai > bi) continue;
    mint tmp = a_dp[ai][n] * b_dp[bi][n];
    ans += tmp;
  }
  cout << ans.val() << endl;
}