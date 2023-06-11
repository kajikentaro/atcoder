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

struct UF {
  vector<int> not_power_cnt;
  vector<int> uf;
  int ans;
  UF(int n, int city) : uf(n, -1), not_power_cnt(n, 0), ans(0) {
    for (int i = 0; i < city; i++) not_power_cnt[i] = 1;
  }
  int find(int a) {
    if (uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
  }
  int size(int a) { return -uf[find(a)]; }
  int merge(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return 0;
    if (size(ra) < size(rb)) swap(ra, rb);  // sb is smaller

    if (not_power_cnt[ra] >= 1 && not_power_cnt[rb] == 0) {
      ans += not_power_cnt[ra];
      not_power_cnt[ra] = 0;
    }
    if (not_power_cnt[rb] >= 1 && not_power_cnt[rb] == 0) {
      ans += not_power_cnt[rb];
      not_power_cnt[rb] = 0;
    }

    not_power_cnt[ra] += not_power_cnt[rb];
    uf[ra] += uf[rb];
    uf[rb] = ra;

    return 1;
  }
  int same(int a, int b) {
    if (find(a) == find(b)) return 1;
    return 0;
  }
};

signed main() {
  int n, m, e;
  cin >> n >> m >> e;

  vector<P> path_history(e);
  set<P> path;
  rep(i, e) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path.emplace(a, b);
    path_history[i] = P{a, b};
  }

  int q;
  cin >> q;
  vector<P> query(q);
  rep(i, q) {
    int a;
    cin >> a;
    a--;
    query[i] = path_history[a];
    path.erase(query[i]);
  }

  UF uf(n + m, n);
  for (auto p : path) {
    uf.merge(p.first, p.second);
  }

  vector<int> ans(q);
  rrep(i, q) {
    ans[i] = uf.ans;
    uf.merge(query[i].first, query[i].second);
  }

  rep(i, q) cout << ans[i] << endl;
}