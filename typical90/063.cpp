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
vector<vector<int>> p;
int h, w;
int func(vector<int> &selected_row) {
  map<int, int> each_num_cnt;
  if (selected_row.size() == 0) return 0;
  rep(j, w) {
    bool all_col_is_same = true;
    int col_num = p[selected_row[0]][j];
    for (auto i : selected_row) {
      if (p[i][j] != col_num) all_col_is_same = false;
    }
    if (all_col_is_same) {
      each_num_cnt[col_num] += selected_row.size();
    }
  }
  int ans = 0;
  for (auto i : each_num_cnt) {
    chmax(ans, i.second);
  }
  return ans;
}
int main() {
  cin >> h >> w;
  p.resize(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> p[i][j];
  int ans = 0;
  rep(i, 1 << h) {
    vector<int> selected_row;
    rep(j, h) {
      if (!(i >> j & 1)) continue;
      selected_row.push_back(j);
    }
    chmax(ans, func(selected_row));
  }
  cout << ans << endl;
}
