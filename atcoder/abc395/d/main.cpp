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
    swap(ra, rb);
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
  int n, q;
  cin >> n >> q;
  vector<int> label_to_idx(n);
  vector<int> idx_to_label(n);
  rep(i, n) label_to_idx[i] = i;
  rep(i, n) idx_to_label[i] = i;

  map<int, int> a_to_idx;
  rep(i, n) a_to_idx[i] = i;
  rep(i, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, label;
      cin >> a >> label;
      a--;
      label--;
      a_to_idx[a] = label_to_idx[label];
    }
    if (type == 2) {
      int label1, label2;
      cin >> label1 >> label2;
      label1--;
      label2--;

      int idx1 = label_to_idx[label1];
      int idx2 = label_to_idx[label2];

      swap(label_to_idx[label1], label_to_idx[label2]);
      swap(idx_to_label[idx1], idx_to_label[idx2]);
    }
    if (type == 3) {
      int a;
      cin >> a;
      a--;
      int idx = a_to_idx[a];
      cout << idx_to_label[idx] + 1 << endl;
      ;
    }
  };
}