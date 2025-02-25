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
vector<vector<int>> path_reverse;
stack<int> root_prior;

vector<bool> is_used;

void dfs1(int now_p) {
  if (is_used[now_p]) return;
  is_used[now_p] = true;

  for (int next_p : path[now_p]) {
    dfs1(next_p);
  }
  root_prior.push(now_p);
}

vector<vector<int>> scc_ans;
vector<int> tmp_scc;

void dfs2(int now_p) {
  if (is_used[now_p]) return;
  is_used[now_p] = true;
  tmp_scc.push_back(now_p);

  for (int next_p : path_reverse[now_p]) {
    dfs2(next_p);
  }
  root_prior.push(now_p);
}

vector<vector<int>> decompose_scc() {
  int n, m;
  cin >> n >> m;
  path.resize(n);
  path_reverse.resize(n);
  is_used.resize(n, false);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path_reverse[b].push_back(a);
  }

  rep(i, n) { dfs1(i); }

  is_used.assign(n, false);
  while (root_prior.size()) {
    int p = root_prior.top();
    root_prior.pop();
    dfs2(p);
    if (tmp_scc.size()) {
      scc_ans.push_back(tmp_scc);
      tmp_scc.resize(0);
    }
  }
  return scc_ans;
}
signed main() {
  auto res = decompose_scc();

  int ans = 0;
  for (auto &nodes : res) {
    if (nodes.size() <= 1) continue;
    int nn = nodes.size();
    ans += nn * (nn - 1) / 2;
  }
  cout << ans << endl;
}