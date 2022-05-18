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
  int n;
  string s;
  cin >> n >> s;
  int idx_o = -1;
  int idx_x = -1;

  vector<int> o_list(n);
  vector<int> x_list(n);
  rrep(i, n) {
    if (s[i] == 'o') {
      idx_o = i;
      o_list[i] = idx_x;
    } else {
      idx_x = i;
      x_list[i] = idx_o;
    }
  }

  ll ans = 0;
  rep(i, n) {
    if (s[i] == 'o') {
      if (o_list[i] == -1) continue;
      ans += n - o_list[i];
    } else {
      if (x_list[i] == -1) continue;
      ans += n - x_list[i];
    }
  }
  cout << ans << endl;
}