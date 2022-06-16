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
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  orep(b, n) {
    ll res_per_group = b - k;
    if (res_per_group <= 0) continue;

    ll group_len = n / b;
    ll ans1 = group_len * res_per_group;
    ans += ans1;

    ll surplus_len = n % b;
    if (k == 0) {
      ans += surplus_len++;
      continue;
    }
    if (surplus_len <= k - 1) continue;
    ll ans2 = surplus_len - (k - 1);
    ans += ans2;
  }
  cout << ans << endl;
}