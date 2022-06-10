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
  ll q;
  cin >> q;
  multiset<ll> set;
  rep(i, q) {
    ll t;
    cin >> t;
    switch (t) {
      case 1: {
        ll x;
        cin >> x;
        set.insert(x);
        break;
      }
      case 2: {
        ll x, k;
        cin >> x >> k;
        auto itr = set.lower_bound(x + 1);

        bool flag = true;
        rep(i, k) {
          if (itr != set.begin()) {
            itr--;
          } else {
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << *itr << endl;
        } else {
          cout << -1 << endl;
        }
        break;
      }
      case 3: {
        ll x, k;
        cin >> x >> k;
        auto itr = set.upper_bound(x - 1);
        // auto itr = set.lower_bound(x);

        bool flag = true;
        rep(i, k - 1) {
          if (itr != set.end()) {
            itr++;
          } else {
            flag = false;
            break;
          }
        }
        if (flag && itr != set.end()) {
          cout << *itr << endl;
        } else {
          cout << -1 << endl;
        }
        break;
      }
    }
  }
}