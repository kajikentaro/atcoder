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
vector<vector<int>> rpath;

signed main() {
  int n, m;
  cin >> n >> m;
  path.resize(n);
  rpath.resize(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    path[a].push_back(b);
    rpath[b].push_back(a);
  }

  vector<int> parent_size(n);
  set<int> can;
  rep(i, n) {
    if (rpath[i].size() == 0) {
      can.insert(i);
    }
    parent_size[i] = rpath[i].size();
  }

  vector<bool> used(n);
  for (auto n : can) {
    used[n] = true;
  }
  vector<int> ans;
  while (can.size()) {
    int now = *can.begin();
    can.erase(now);

    ans.push_back(now);
    for (auto next : path[now]) {
      if (used[next]) continue;
      parent_size[next]--;
      if (parent_size[next] == 0) {
        can.insert(next);
        used[next] = true;
      }
    }
  }

  if (ans.size() == n) {
    for (auto a : ans) {
      cout << a + 1 << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
