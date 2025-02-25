#include <bits/stdc++.h>

#include <atcoder/all>
#define int long long
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

ll MAX = 1e18 + 10;

tuple<int, int, int> normalize(int a, int b) {
  if (a == 0) {
    return {MAX, 0, 0};
  }
  if (b == 0) {
    return {MAX, 0, 1};
  }
  int minus = 1;
  if (a < 0) {
    minus *= -1;
    a *= -1;
  }
  if (b < 0) {
    minus *= -1;
    b *= -1;
  }
  int g = gcd(a, b);

  if (minus == -1) {
    return {b / g, a / g, 1};
  } else {
    return {a / g, b / g, 0};
  }
}

signed main() {
  int n;
  cin >> n;

  map<P, P> d;

  int all_zero = 0;

  rep(i, n) {
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0) {
      all_zero++;
      continue;
    }

    auto [chi, mom, type] = normalize(a, b);
    P p = {chi, mom};
    if (type) {
      d[p].second++;
    } else {
      d[p].first++;
    }
  };

  mint ans = 1;
  for (auto &[_, cnt] : d) {
    mint aa = (mint(2)).pow(cnt.first) - 1;
    mint bb = (mint(2)).pow(cnt.second) - 1;

    ans *= (aa + bb + 1);
  }

  ans += all_zero - 1;

  cout << ans.val() << endl;
}