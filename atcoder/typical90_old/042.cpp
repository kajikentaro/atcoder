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
<<<<<<< HEAD:typical90/042.cpp
  ll k;
  ll mod = (ll)1e9 + 7;
  cin >> k;
  vector<ll> dp(k + 20);
  dp[0] = 1;
  if (k % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, k + 10) {
    orep(j, 9) { dp[i + j] = (dp[i + j] + dp[i]) % mod; }
  }
  cout << dp[k] << endl;
}
=======
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  int b = a[1];
  sort(a.begin(), a.end());
  if (b == a[1]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
>>>>>>> 46143fa18b634a19f9d5ad74c099ec9113724ba5:abc/253a.cpp
