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
  string input;
  cin >> input;

  string bottom;
  {
    ll n;
    cin >> n;
    stringstream ss;
    ss << bitset<64>(n);
    bottom = ss.str();
  }

  string up = bottom;
  {
    rep(i, up.size()) up[i] = '0';

    int si = up.size() - 1;
    rrep(i, input.size()) {
      up[si] = input[i];
      si--;
    }
  }

  // dp[i桁目][strict] = ans
  vector<vector<ll>> dp(up.size(), vector<ll>(2, -1));
  dp[0][1] = 0;

  rep(i, up.size()) {
    if (i == 0) continue;
    if (up[i] == '0') {
      if (bottom[i] == '0') {
        chmax(dp[i][0], dp[i - 1][0] * 2);
        chmax(dp[i][1], dp[i - 1][1] * 2);
      }
      if (bottom[i] == '1') {
        chmax(dp[i][0], dp[i - 1][0] * 2);
        chmax(dp[i][0], dp[i - 1][1] * 2);
      }
    }
    if (up[i] == '1') {
      if (bottom[i] == '0') {
        chmax(dp[i][0], dp[i - 1][0] * 2 + 1);
        // chmax(dp[i][1], dp[i - 1][1] * 2);
      }
      if (bottom[i] == '1') {
        chmax(dp[i][0], dp[i - 1][0] * 2 + 1);
        chmax(dp[i][1], dp[i - 1][1] * 2 + 1);
      }
    }
    if (up[i] == '?') {
      if (bottom[i] == '0') {
        chmax(dp[i][0], dp[i - 1][0] * 2 + 1);
        chmax(dp[i][1], dp[i - 1][1] * 2);
      }
      if (bottom[i] == '1') {
        chmax(dp[i][0], dp[i - 1][0] * 2 + 1);
        chmax(dp[i][0], dp[i - 1][1] * 2);

        chmax(dp[i][1], dp[i - 1][1] * 2 + 1);
      }
    }
  }

  ll ans = max(dp[dp.size() - 1][0], dp[dp.size() - 1][1]);
  cout << ans << endl;
}