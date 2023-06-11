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
vector<vector<int>> store;
void print_store(int a, int b, int c, int d) { store.push_back({a, b, c, d}); }

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));

  rep(i, h) rep(j, w) {
    cin >> a[i][j];
    a[i][j] %= 2;
  }

  rep(i, h) {
    rep(j, w - 1) {
      if (a[i][j] % 2 == 1) {
        a[i][j + 1] = (a[i][j + 1] + 1) % 2;
        print_store(i + 1, j + 1, i + 1, j + 2);
      }
    }
  }

  rep(i, h - 1) {
    if (a[i][w - 1] % 2 == 1) {
      a[i + 1][w - 1] = (a[i + 1][w - 1] + 1) % 2;
      print_store(i + 1, w, i + 2, w);
    }
  }

  cout << store.size() << endl;
  for (auto s : store) {
    printf("%d %d %d %d\n", s[0], s[1], s[2], s[3]);
  }
}