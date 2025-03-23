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

void print(P p) { cout << p.first + 1 << " " << p.second + 1 << endl; }

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> path(n);
  vector<P> path_backup;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);

    path_backup.emplace_back(a, b);
  };

  vector<bool> type(n);
  {
    vector<bool> used(n);
    function<void(int, bool)> dfs;
    dfs = [&](int now, bool t) {
      if (used[now]) {
        return;
      }
      used[now] = true;
      type[now] = t;
      for (auto next : path[now]) {
        dfs(next, !t);
      }
    };
    dfs(0, false);
  }

  vector<vector<bool>> ng(n, vector<bool>(n, false));
  rep(i, n) { ng[i][i] = true; }
  for (auto [a, b] : path_backup) {
    ng[a][b] = true;
    ng[b][a] = true;
  }
  rep(i, n) rep(j, n) {
    if (type[i] == type[j]) {
      ng[i][j] = true;
      ng[j][i] = true;
    }
  }

  set<P> se;
  rep(i, n) rep(j, i) {
    if (ng[i][j] == false) {
      se.insert(P{j, i});
    }
  }

  if (se.size() % 2) {
    cout << "First" << endl;

    auto it = se.begin();
    print(*it);
    se.erase(it);
  } else {
    cout << "Second" << endl;
  }

  while (se.size()) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);  // a is small
    auto it = se.find(P{a, b});
    se.erase(it);

    {
      auto it = se.begin();
      print(*it);
      se.erase(it);
    }
  }
}