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
int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
ll sum(ll n, ll a) { return n * a * (n + 1) / 2; }
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ab = lcm(a, b);
  ll n_sum = sum(n, 1);
  ll a_sum = sum(n / a, a);
  ll b_sum = sum(n / b, b);
  ll ab_sum = sum(n / ab, ab);
  ll ans = n_sum - a_sum - b_sum + ab_sum;
  cout << ans << endl;
}
