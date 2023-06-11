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
#define int long long
using P = pair<int, int>;

int n, m;
int get_idx(int t_pos, int a_pos) { return t_pos * n + a_pos; }

int sub() {
  cin >> n >> m;
  vector<int> color(n);
  rep(i, n) cin >> color[i];

  vector<vector<int>> path_tmp(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path_tmp[a].push_back(b);
    path_tmp[b].push_back(a);
  }

  int n2 = n * n;

  vector<vector<int>> path(n2);
  rep(t_pos, n) rep(a_pos, n) {
    if (color[t_pos] == color[a_pos]) continue;
    int idx = get_idx(t_pos, a_pos);

    for (auto new_t_pos : path_tmp[t_pos]) {
      for (auto new_a_pos : path_tmp[a_pos]) {
        if (idx == get_idx(new_t_pos, new_a_pos)) continue;
        if (color[new_t_pos] == color[new_a_pos]) continue;
        path[idx].emplace_back(get_idx(new_t_pos, new_a_pos));
      }
    }
  }

  // used.resize(n2);
  // int res = dfs(path, get_idx(0, n - 1), get_idx(n - 1, 0));

  // bfs
  queue<P> que;
  que.emplace(P{get_idx(0, n - 1), 0});
  vector<bool> used(n2);

  while (que.size()) {
    auto now = que.front();
    que.pop();
    if (used[now.first]) continue;
    used[now.first] = true;

    if (now.first == get_idx(n - 1, 0)) {
      return now.second;
    }

    for (auto next : path[now.first]) {
      que.emplace(P{next, now.second + 1});
    }
  }
  return -1;
}

signed main() {
  int t;
  cin >> t;
  rep(i, t) cout << sub() << endl;
}
