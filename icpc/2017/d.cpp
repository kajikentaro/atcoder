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
void full_search(int n, int m) {
  int ans = 0;
  vector<vector<int>> items(n, vector<int>(m));
  rep(i, n) {
    string input;
    cin >> input;
    rep(j, m) { items[i][j] = input[j] - '0'; }
  }

  for (int bit = 0; bit < (1 << n); bit++) {
    vector<int> num(m);
    int anst = 0;
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        anst++;
        rep(j, m) { num[j] += items[i][j]; }
      }
    }
    int jc = 0;
    rep(i, m) {
      if (num[i] % 2 == 0) {
        jc++;
      }
    }

    if (jc == m) {
      ans = max(ans, anst);
    }
  }

  cout << ans << endl;
}

void do_dp(ll n, ll m) {
  // m is smaller than 23

  vector<ll> items(n);
  rep(i, n) {
    string input;
    cin >> input;
    rep(j, m) {
      items[i] = items[i] << 1;
      if (input[j] - '0') {
        items[i] = items[i] | 1;
      }
    }
  }

  vector<ll> dp(1 << m);

  rep(i, n) {
    vector<ll> dp_old = dp;
    swap(dp_old, dp);
    for (ll bit = 0; bit < (1ll << m); bit++) {
      if (bit ^ items[i] == 0) {
        chmax(dp[bit], dp_old[bit ^ items[i]] + 1);
      } else if (dp_old[bit ^ items[i]] >= 1) {
        chmax(dp[bit], dp_old[bit ^ items[i]] + 1);
      }
    }
  }

  cout << dp[0] << endl;
}

bool func() {
  int n, m;
  cin >> n >> m;
  if (n + m == 0) return false;
  if (n <= 23) {
    full_search(n, m);
  } else {
    do_dp(n, m);
  }
  return true;
}
int main() {
  while (func()) {
    ;
  }
}