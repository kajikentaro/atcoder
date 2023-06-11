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
  vector<ll> a(100);
  a[0] = 1;
  rep(i, n) {
    if (i == 0) {
      cout << 1 << endl;
      continue;
    }
    vector<ll> b(100);
    swap(a, b);
    rep(j, i + 1) {
      if (j == 0 || j == i) {
        cout << 1 << " ";
        a[j] = 1;
      } else {
        a[j] = b[j - 1] + b[j];
        cout << a[j] << " ";
      }
    }
    cout << endl;
  }
}