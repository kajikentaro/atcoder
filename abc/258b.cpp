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
  ll n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(n));

  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) { a[i][j] = s[j] - '0'; }
  }

  ll ans = 0;
  rep(i, n) rep(j, n) {
    const P dirs[] = {{0, 1}, {0, -1}, {1, 0},   {1, -1},
                      {1, 1}, {-1, 0}, {-1, -1}, {-1, 1}};
    for (auto d : dirs) {
      ll s_ans = 0;
      ll ni = i;
      ll nj = j;
      rep(c, n) {
        ni += d.first;
        nj += d.second;
        ni = (ni + n) % n;
        nj = (nj + n) % n;
        s_ans *= 10;
        s_ans += a[ni][nj];
      }
      chmax(ans, s_ans);
    }
  }

  cout << ans << endl;
}