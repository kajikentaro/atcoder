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
  int n, m;
  cin >> n >> m;

  map<int, int> white;
  map<int, int> black;

  priority_queue<int, vector<int>, greater<int>> x_list;
  rep(i, m) {
    int x, y;
    char c;
    cin >> y >> x >> c;
    y = n - y + 1;
    if (c == 'B') {
      if (black.count(x) == 0)
        black[x] = y;
      else
        chmin(black[x], y);
    } else {
      chmax(white[x], y);
    }
    x_list.push(x);
  }

  int white_y_max = 0;
  while (x_list.size()) {
    int x = x_list.top();
    x_list.pop();

    int white_y = max(white[x], white_y_max);
    int black_y = black.count(x) ? black[x] : white_y + 1;
    if (black_y <= white_y) {
      cout << "No" << endl;
      return 0;
    }

    white_y_max = white_y;
  }

  cout << "Yes" << endl;

  ;
}