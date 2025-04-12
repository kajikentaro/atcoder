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
  UF(int n) : uf(n, -1) {}
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
  int n, m;
  cin >> n >> m;
  UF uf(n);
  int ans = 0;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (uf.same(a, b)) {
      ans++;
    } else {
      uf.merge(a, b);
    }
  }
  cout << ans << endl;
  ;
}