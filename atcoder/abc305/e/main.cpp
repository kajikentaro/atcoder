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

struct Gurdman {
  int p, h;
};

bool operator<(const Gurdman &a, const Gurdman &b) { return a.h < b.h; }

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> path(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  };

  priority_queue<Gurdman, vector<Gurdman>, less<Gurdman>> que;
  rep(i, k) {
    int p, h;
    cin >> p >> h;
    p--;
    Gurdman g = {p, h};
    que.push(g);
  }

  vector<bool> is_gurded(n);
  while (que.size()) {
    Gurdman g = que.top();
    que.pop();

    if (is_gurded[g.p]) {
      continue;
    }
    is_gurded[g.p] = true;
    if (g.h == 0) continue;
    for (auto p : path[g.p]) {
      if (is_gurded[p]) {
        continue;
      }
      Gurdman ng = {p, g.h - 1};
      que.push(ng);
    }
  }

  int sum = 0;
  vector<int> res;
  rep(i, n) {
    if (is_gurded[i]) {
      res.push_back(i + 1);
      sum++;
    }
  }

  cout << res.size() << endl;
  rep(i, res.size()) {
    if (i == res.size() - 1) {
      cout << res[i] << endl;
    } else {
      cout << res[i] << " ";
    }
  }
}
