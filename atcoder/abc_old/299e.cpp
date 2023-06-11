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
vector<set<int>> mark;

vector<int> used;
void dfs(int p, int d, int start) {
  if (used[p]) return;
  used[p] = 1;
  if (d == 0) {
    mark[p].emplace(start);
    return;
  }

  for (auto next : path[p]) {
    dfs(next, d - 1, start);
  }
}

void dfs2(int p, int d, int start) {
  if (used[p]) return;
  used[p] = 1;

  if (d == 0) return;

  mark[p].clear();
  for (auto next : path[p]) {
    dfs2(next, d - 1, start);
  }
}

struct Q {
  int p, d, start;
};

int main() {
  int n, m;
  cin >> n >> m;
  path.resize(n);
  mark.resize(n);
  rep(i, n) { mark[i].emplace(-1); }

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }

  int k;
  cin >> k;
  vector<int> Ps(k);
  vector<int> Ds(k);
  rep(i, k) {
    cin >> Ps[i] >> Ds[i];
    Ps[i]--;
  }

  rep(i, k) {
    queue<Q> que;
    used = vector<int>(n, 0);
    que.emplace(Q{Ps[i], Ds[i], Ps[i]});

    while (que.size()) {
      Q tmp = que.front();
      que.pop();
      int p, d, start;
      p = tmp.p;
      d = tmp.d;
      start = tmp.start;

      if (used[p]) continue;
      used[p] = 1;
      if (d == 0) {
        mark[p].emplace(start);
        continue;
      }

      for (auto next : path[p]) {
        if (used[next]) continue;
        que.emplace(Q{next, d - 1, start});
      }
    }
  }

  rep(i, k) {
    used = vector<int>(n, 0);
    queue<Q> que;
    que.emplace(Q{Ps[i], Ds[i], Ps[i]});

    while (que.size()) {
      Q tmp = que.front();
      que.pop();
      int p, d, start;
      p = tmp.p;
      d = tmp.d;
      start = tmp.start;

      if (used[p]) continue;
      used[p] = 1;
      if (d == 0) {
        continue;
      }

      mark[p].clear();
      for (auto next : path[p]) {
        if (used[next]) continue;
        que.emplace(Q{next, d - 1, start});
      }
    }
  }

  set<int> isOk;
  vector<int> ans(n);
  rep(i, n) {
    if (mark[i].size()) {
      ans[i] = 1;
    }
    for (auto p : mark[i]) {
      isOk.emplace(p);
    }
  }

  if (isOk.size() != k + 1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for (auto a : ans) {
    cout << a;
  }
  cout << endl;
}