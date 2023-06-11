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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];

  vector<set<int>> hate(n);
  int m;
  cin >> m;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    hate[x].insert(y);
    hate[y].insert(x);
  }

  vector<int> order(n);
  rep(i, n) order[i] = i;
  sort(order.begin(), order.end());

  ll ans = 1e18;
  do {
    ll score = 0;
    rep(i, n) {
      if (i != 0 && hate[order[i]].count(order[i - 1])) {
        score = 1e18;
        break;
      };
      score += a[order[i]][i];
    }
    if (score == 1179) {
      cout << "hoge" << endl;
    }
    chmin(ans, score);
  } while (next_permutation(order.begin(), order.end()));
  if (ans == 1e18) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}