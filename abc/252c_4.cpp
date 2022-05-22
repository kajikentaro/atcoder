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
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int ans = 1e9;
  rep(target, 10) {
    vector<int> stop_time(10);
    rep(i, n) rep(j, 10) {
      int s_num = s[i][j] - '0';
      if (s_num == target) {
        stop_time[j]++;
      }
    }

    auto is_ok = [&]() {
      rep(i, 10) {
        if (stop_time[i]) return false;
      }
      return true;
    };

    int res;
    rep(i, 1e9) {
      res = i;
      if (stop_time[i % 10]) stop_time[i % 10]--;
      if (is_ok()) break;
    }

    chmin(ans, res);
  }
  cout << ans << endl;
}