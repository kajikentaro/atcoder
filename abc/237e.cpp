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
struct Path {
  int next, fun;
  Path(int next, int fun) : next(next), fun(fun) {}
};
vector<vector<Path>> path;
vector<int> h;

ll get_fun(int from, int to) {
  if (h[from] >= h[to]) {
    return h[from] - h[to];
  } else {
    return 2 * (h[to] - h[from]);
  }
}
vector<bool> used;
vector<ll> fun_dest;
void dfs(int p, int now_fun) {
  if (used[p]) return;
  used[p] = true;
  for (auto n : path[p]) {
    dfs(n.next, now_fun + n.fun);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  path.resize(n);
  h.resize(n);
  used.resize(n, false);

  rep(i, n) cin >> h[i];
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    path[u].emplace_back(v, get_fun(u, v));
    path[v].emplace_back(u, get_fun(v, u));
  }

  dfs(0);
}
