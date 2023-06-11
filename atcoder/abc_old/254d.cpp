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
map<ll, ll> bunkai(ll n) {
  map<ll, ll> k;
  k[1]++;
  for (ll i = 2; i * i <= n;) {
    if (n % i == 0) {
      k[i]++;
      n /= i;
      continue;
    } else {
      i++;
    }
  }
  if (n != 1) k[n]++;
  return k;
}
int main() {
  ll n;
  cin >> n;
  vector<ll> heiho_list;
  orep(i, n) {
    if ((ll)i * i > n) break;
    heiho_list.push_back((ll)i * i);
  }

  ll ans = 0;
  orep(i, n) {
    map<ll, ll> b = bunkai(i);
    ll must_n = 1;
    for (auto e : b) {
      ll cnt = e.second;
      if (cnt % 2) {
        must_n *= e.first;
      }
    }

    ll ac = 0;
    ll wa = heiho_list.size();
    while (wa - ac != 1) {
      ll wj = (ac + wa) / 2;
      if (must_n * heiho_list[wj] <= n) {
        ac = wj;
      } else {
        wa = wj;
      }
    }
    ans += ac + 1;
  }
  cout << ans << endl;
}