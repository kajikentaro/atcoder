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

struct Cable {
  int c;      // cable number
  int s;      // server number
  int after;  // for answer
  Cable(int c, int s, int a) : c(c), s(s), after(a) {}
};

struct UF {
  vector<int> uf;
  vector<list<Cable>> unused;
  stack<int> unused_node;
  set<int> root_list;
  int n;
  UF(int n) : uf(n, -1), unused(n), n(n) { rep(i, n) root_list.emplace(i); }
  int find(int a) {
    if (uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
  }
  int size(int a) { return -uf[find(a)]; }
  int merge(int a, int b, int c) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) {
      unused[ra].push_back(Cable(c, a, -1));
      unused_node.push(a);
      return 0;
    }
    if (size(ra) < size(rb)) swap(ra, rb);  // sb is smaller
    uf[ra] += uf[rb];
    uf[rb] = ra;  // ra is new root

    auto &old_unused = unused[rb];
    unused[ra].splice(unused[ra].end(), old_unused);
    root_list.erase(rb);
    return 1;
  }
  int same(int a, int b) {
    if (find(a) == find(b)) return 1;
    return 0;
  }
};

signed main() {
  int n, m;
  cin >> n >> m;
  UF uf(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    uf.merge(a, b, i);
  }

  vector<Cable> ans;
  while (uf.root_list.size() != 1) {
    int node = uf.unused_node.top();
    uf.unused_node.pop();
    int root = uf.find(node);

    int another_root = *uf.root_list.begin();
    if (another_root == root) {
      another_root = *++uf.root_list.begin();
    }

    Cable cable = *uf.unused[root].begin();
    uf.unused[root].pop_front();
    ans.push_back(Cable(cable.c, cable.s, another_root));

    uf.merge(cable.s, another_root, cable.c);
    int new_root = uf.find(another_root);
  }

  cout << ans.size() << endl;
  for (auto &a : ans) {
    printf("%lld %lld %lld\n", a.c + 1, a.s + 1, a.after + 1);
  }
}
