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

struct Path {
  vector<vector<int>> path;
  Path(int size) { path.resize(size); }
};

struct Point {
  int idx, num, dist;
};
signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<vector<int>> s(n);
  rep(i, n) {
    cin >> a[i];
    rep(j, a[i]) {
      int ss;
      cin >> ss;
      s[i].push_back(ss);
    }
  }

  map<int, vector<int>> num_to_idx_list;
  rep(i, n) {
    rep(j, a[i]) {
      int num = s[i][j];
      num_to_idx_list[num].push_back(i);
    }
  }

  queue<Point> que;
  for (auto idx : num_to_idx_list[1]) {
    que.push(Point{idx, 1, 0});
  }
  vector<map<int, bool>> used(n);
  vector<bool> used_idx(n);
  vector<bool> used_num(m + 1);
  while (que.size()) {
    Point now = que.front();
    que.pop();
    if (used[now.idx][now.num]) continue;
    used[now.idx][now.num] = true;
    if (now.num == m) {
      cout << now.dist << endl;
      return 0;
    }
    if (!used_idx[now.idx]) {
      for (auto next_num : s[now.idx]) {
        que.push(Point{now.idx, next_num, now.dist + 0});
      }
    }
    used_idx[now.idx] = true;

    if (!used_num[now.num]) {
      for (auto next_idx : num_to_idx_list[now.num]) {
        que.push(Point{next_idx, now.num, now.dist + 1});
      }
    }
    used_num[now.num] = true;
  }
  cout << -1 << endl;
}
