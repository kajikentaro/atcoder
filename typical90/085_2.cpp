#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
int main() {
  ll n;
  vector<ll> k;
  cin >> n;
  for (ll i = 1; i * i <= n; i++) {
    if (i * i == n) {
      k.push_back(i);
    } else if (n % i == 0) {
      k.push_back(i);
      k.push_back(n / i);
    }
  }
  ll s = k.size();
  ll ans = 0;
  rep(i, s) rep(j, s) {
    ll a = k[i];
    ll b = k[j];
    if (a > b) continue;
    if (a > n / b) continue;
    ll ab = a * b;
    if (n % ab) continue;
    ll c = n / ab;
    if (b > c) continue;
    ans++;
  }
  cout << ans << endl;
}