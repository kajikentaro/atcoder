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

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll g = gcd(a, b);
  a /= g;

  ll test = (ll)1e18 / a;
  if (b <= test) {
    cout << a * b << endl;
  } else {
    cout << "Large" << endl;
  }
}
