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

signed main() {
  int d;
  cin >> d;
  vector<int> can;
  rep(i, 1e18) {
    int t = i * i;
    can.push_back(t);
    if (t >= d) {
      rep(j, 3) {
        i++;
        can.push_back(i * i);
      }
      break;
    }
  };

  // | a + y |
  int ans = 1e18;
  for (auto c : can) {
    int a = c - d;
    if (a >= 0) {
      chmin(ans, a);
    } else {
      int b = -a;
      auto up = lower_bound(can.begin(), can.end(), b);

      int y1 = *up;
      int y2 = *--up;
      chmin(ans, abs(y1 + a));
      chmin(ans, abs(y2 + a));
    }
  }

  cout << ans << endl;
}