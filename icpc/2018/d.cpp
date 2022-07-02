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
const char WIN = 1;
const char LOSE = 2;
int n;

ll dfs(vector<vector<char>> old_table, vector<int> must_win_old, int hi) {
  ll ans = 0;
  if (hi == n) {
    return 1;
  }
  int w = n - hi - 1;
  int start = hi + 1;
  for (unsigned int bit = 0; bit < 1 << w; bit++) {
    auto table = old_table;
    auto must_win = must_win_old;
    if (__builtin_popcount(bit) != must_win_old[hi]) continue;
    bool ok = true;
    rep(bi, w) {
      int result;
      if (bit >> bi & 1)
        result = WIN;
      else
        result = LOSE;

      int wi = bi + start;
      if (table[hi][wi] == result || table[hi][wi] == 0) {
        table[hi][wi] = result;
        table[wi][hi] = result == WIN ? LOSE : WIN;
      } else {
        ok = false;
        break;
      }
      if (result == WIN) {
        must_win[hi]--;
      } else {
        must_win[wi]--;
      }
    }
    if (ok) {
      ll tmp = dfs(table, must_win, hi + 1);
      ans += tmp;
    }
  }
  return ans;
}

bool func() {
  cin >> n;
  if (n == 0) return false;
  vector<vector<char>> table(n, vector<char>(n));
  int m;
  cin >> m;
  vector<int> must_win(n, (n - 1) / 2);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    table[x][y] = WIN;
    table[y][x] = LOSE;
  }

  cout << dfs(table, must_win, 0) << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}