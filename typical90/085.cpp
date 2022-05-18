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
  cin >> n;
  vector<ll> k;
  for (ll i = 2; i * i <= n;) {
    if (n % i == 0) {
      k.push_back(i);
      n /= i;
      continue;
    } else {
      i++;
    }
  }
  if (n != 1) k.push_back(n);

  int s = k.size();
  set<P> ans;
  rep(i, pow(3, s)) {
    ll res[] = {1, 1, 1};
    rep(j, s) {
      int bit = (i / (int)pow(3, j)) % 3;
      res[bit] *= k[j];
    }
    if (res[0] <= res[1] && res[1] <= res[2]) {
      ans.emplace(res[0], res[1]);
    }
  }
  cout << ans.size() << endl;
}