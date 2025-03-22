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

int op(int a, int b) { return a + b; }
int e() { return 0; }

int n, x;
void solve(vector<int> a) {
  segtree<int, op, e> buffer(n + 1);

  rep(i, n) {
    if (i == 0) continue;
    int diff = a[i] - a[i - 1];
    if (diff < x) {
      buffer.set(i, diff);
    }
    if (diff > x) {
    }
  }
}

signed main() {
  cin >> n >> x;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) { cin >> a[i] >> b[i]; };

  solve(a);
}