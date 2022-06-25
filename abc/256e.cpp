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

int main() {
  int n;
  cin >> n;
  path.resize(n);
  path_reverse.resize(n);
  is_used.resize(n, false);

  rep(i, n) {
    int a;
    cin >> a;
    a--;
    path[i].push_back(a);
    path_reverse[a].push_back(i);
  }

  vector<int> cost(n);
  rep(i, n) cin >> cost[i];

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

  ll ans = 0;
  for (auto ring : scc_ans) {
    if (ring.size() == 1) continue;
    int mi = 1e9;
    for (auto r : ring) {
      chmin(mi, cost[r]);
    }
    ans += mi;
  }

  cout << ans << endl;
}