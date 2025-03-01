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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int ans = 1;
  rep(start, n) {
    // n log(n)
    orep(dist, n) {
      int prev_h = -1;
      int current_score = 1;
      for (int cursor = start; cursor < n; cursor += dist) {
        int now_h = h[cursor];
        if (now_h == prev_h) {
          current_score++;
          chmax(ans, current_score);
        } else {
          current_score = 1;
        }

        prev_h = now_h;
      }
    }
  }

  cout << ans << endl;
}