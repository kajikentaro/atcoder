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
  map<char, vector<int>> dirs;
  dirs['U'] = {-1, 0};
  dirs['D'] = {1, 0};
  dirs['L'] = {0, -1};
  dirs['R'] = {0, 1};

  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  string t;
  cin >> t;

  int ans = 0;
  rep(i, t.size()) {
    int x2 = x + dirs[t[i]][0];
    int y2 = y + dirs[t[i]][1];

    char next = s[x2][y2];
    if (next == '#') continue;
    if (next == '.') {
      x = x2;
      y = y2;
      continue;
    }
    if (next == '@') {
      ans++;
      s[x2][y2] = '.';
      x = x2;
      y = y2;
      continue;
    }
  }

  x++;
  y++;
  cout << x << " " << y << " " << ans << endl;
}