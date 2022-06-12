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
int x, y;
ll func(vector<int> a) {
  int n = a.size();
  if (x == y) {
    return (ll)n * (n + 1) / 2;
  }
  // 0, 何もないけど選択中
  // 1, Yのみ選択中
  // 2, Xのみ選択中
  // 3, X, Y選択中
  // 4, X, Y選択終了
  vector<ll> dp(5);
  rep(i, n) {
    if (a[i] == y) {
      dp[1] += dp[0];
      dp[0] = 0;
      dp[1]++;
      dp[3] += dp[2];
      dp[2] = 0;
    } else if (a[i] == x) {
      dp[2] += dp[0];
      dp[0] = 0;
      dp[2]++;
      dp[3] += dp[1];
      dp[1] = 0;
    } else {
      dp[0]++;
    }
    dp[4] += dp[3];
  }
  return dp[4];
}
int main() {
  int n;

  cin >> n >> x >> y;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> a_tmp;
  ll ans = 0;
  rep(i, n) {
    if (y <= a[i] && a[i] <= x) {
      a_tmp.push_back(a[i]);
    } else {
      ans += func(a_tmp);
      a_tmp.resize(0);
    }
  }
  ans += func(a_tmp);
  cout << ans << endl;
}