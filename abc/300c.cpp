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

vector<string> grid;
int h, w;

char get(int i, int j) {
  if (i < 0) return '.';
  if (j < 0) return '.';
  if (i >= h) return '.';
  if (j >= w) return '.';
  return grid[i][j];
}
int solve(int hi, int wi) {
  int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

  if (get(hi, wi) == '.') return 0;

  int size = -1;
  while (1) {
    size++;

    bool isOk = true;
    for (auto d : dir) {
      int now_hi = hi + size * d[0];
      int now_wi = wi + size * d[1];
      if (get(now_hi, now_wi) == '.') {
        isOk = false;
      }
    }

    if (!isOk) break;
  }
  return size - 1;
}

int main() {
  cin >> h >> w;

  grid.resize(h);
  rep(i, h) cin >> grid[i];

  vector<int> ans(min(h, w) + 1);
  rep(i, h) rep(j, w) { ans[solve(i, j)]++; }

  orep(i, min(h, w)) { cout << ans[i] << " "; }
  cout << endl;
}