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

vector<vector<int>> path;
vector<bool> used;
vector<int> can;

signed main() {
  int n;
  cin >> n;
  path.resize(n);
  used.resize(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }

  int score_max = 0;
  rep(c, n) {
    int blue_tmp = path[c].size();
    vector<int> green_tmp;
    for (auto &p : path[c]) {
      int g = path[p].size() - 1;
      green_tmp.push_back(g);
    }
    sort(green_tmp.begin(), green_tmp.end());
    rep(i, green_tmp.size()) {
      int blue = blue_tmp - i;
      int green = blue * green_tmp[i];
      int score = blue + green + 1;
      chmax(score_max, score);
    }
  };

  cout << n - score_max << endl;
}