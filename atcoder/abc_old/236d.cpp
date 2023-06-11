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
vector<vector<int>> a;
map<P, int> memo;
int n;
int func(int candidate, int score) {
  if (candidate == 0) return score;
  if (memo.count({candidate, score}) != 0) return memo[{candidate, score}];
  int res = 0;
  rep(i, 2 * n) {
    if (!(candidate >> i & 1)) continue;
    for (int j = i + 1; j < 2 * n; j++) {
      if (!(candidate >> j & 1)) continue;
      int tmp_res = func(candidate ^ (1 << i) ^ (1 << j), score ^ a[i][j]);
      chmax(res, tmp_res);
    }
  }
  memo[{candidate, score}] = res;
  return res;
}
int main() {
  cin >> n;
  a.resize(2 * n, vector<int>(2 * n, -1));
  rep(i, 2 * n) {
    for (int j = i + 1; j < 2 * n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  int candidate = 1 << (2 * n);
  candidate--;

  int ans = func(candidate, 0);
  cout << ans << endl;
}