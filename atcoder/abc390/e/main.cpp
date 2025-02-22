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

struct Food {
  int a, c;
  Food(int a, int c) : a(a), c(c) {}
};

int n, x;

vector<int> getDp(vector<Food> v) {
  int vn = v.size();

  vector<int> dp(x + 1);
  rep(i, vn) {
    rrep(j, x) {
      int idx = v[i].c + j;
      if (idx >= x + 1) continue;
      chmax(dp[idx], dp[j] + v[i].a);
    }
  }
  return dp;
}

signed main() {
  cin >> n >> x;
  vector<vector<Food>> V(3);
  rep(i, n) {
    int v, a, c;
    cin >> v >> a >> c;
    v--;
    V[v].emplace_back(a, c);
  }

  vector<vector<int>> dp;
  rep(i, 3) { dp.push_back(getDp(V[i])); }

  int ans = 0;
  rep(i, x) rep(j, x) {
    int k = x - i - j;
    if (k < 0) continue;

    int v0_ans = dp[0][i];
    int v1_ans = dp[1][j];
    int v2_ans = dp[2][k];

    chmax(ans, min(v0_ans, min(v1_ans, v2_ans)));
  }

  cout << ans << endl;
}
