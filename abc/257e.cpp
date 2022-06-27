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
struct Point {
  int size, pre_h = -1, pre_w = -1;
};
int main() {
  int n;
  cin >> n;
  vector<ll> item_list(9);
  rep(i, 9) cin >> item_list[i];

  vector<vector<Point>> dp(9, vector<Point>(n + 1));
  rep(i, 9) {
    ll item = item_list[i];
    orep(j, n) {
      if (j - item < 0) {
        continue;
      }
      while (1) {
        Point target = dp[i - 1][j];
        if (target.size + 1 < dp[i][j].size) break;
        dp[i][j] = target.size + 1;
        dp[i][j].pre_h = i - 1;
        dp[i][j].pre_w = j;
      }
      while (1) {
        Point target = dp[i][j - item];
        if (target.size + 1 < dp[i][j].size) break;
        dp[i][j] = target.size + 1;
        dp[i][j].pre_h = i;
        dp[i][j].pre_w = j - item;
      }
    }
  }
  rrep(i, dp[n].size()) { cout << dp[n][i]; }
  cout << endl;
}