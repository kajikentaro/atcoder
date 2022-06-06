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
    if (size(ra) < size(rb)) swap(ra, rb);
    uf[ra] += uf[rb];
    uf[rb] = ra;
    return 1;
  }
  int same(int a, int b) {
    if (find(a) == find(b)) return 1;
    return 0;
  }
  bool is_ok() {
    rep(i, uf.size()) {
      if (!same(0, i)) {
        return false;
      }
    }
    return true;
  }
};
int w, h;
int get_id(int y, int x) { return x + (w + y); }
int main() {
  while (1) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    UF uf(h + w);

    rep(i, h + w - 1) {
      int x, y, n;
      cin >> x >> y >> n;
      x--;
      y--;
      uf.merge(x, w + y);
    }
    if (uf.is_ok()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
