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
  vector<int> uf;
  vector<bool> has_power;
  int ans_num = 0;
  UF(int n, int m) : uf(n + m, -1), has_power(n + m, false) {
    for (int i = n; i < n + m; i++) {
      has_power[i] = true;
    }
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

    if (has_power[ra] == false && has_power[rb] == true) {
      ans_num += size(ra);
      has_power[ra] = true;
    }
    if (has_power[rb] == false && has_power[ra] == true) {
      ans_num += size(rb);
      has_power[rb] = true;
    }

    uf[ra] += uf[rb];
    uf[rb] = ra;
    return 1;
  }
  int same(int a, int b) {
    if (find(a) == find(b)) return 1;
    return 0;
  }
  int ans() { return ans_num; }
};

signed main() {
  int n, m, e;
  cin >> n >> m >> e;

  vector<P> path(e);
  rep(i, e) {
    cin >> path[i].first >> path[i].second;
    path[i].first--;
    path[i].second--;
  }

  UF uf(n, m);

  int q;
  cin >> q;
  vector<int> query(q);
  set<int> query_set;
  rep(i, q) {
    cin >> query[i];
    query[i]--;
  }
  rep(i, q) query_set.emplace(query[i]);

  rep(i, e) {
    if (query_set.count(i)) continue;
    uf.merge(path[i].first, path[i].second);
  }

  vector<int> ans(q);
  rrep(i, q) {
    ans[i] = uf.ans();
    uf.merge(path[query[i]].first, path[query[i]].second);
  }

  rep(i, q) cout << ans[i] << endl;
}