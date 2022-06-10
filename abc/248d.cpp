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
int binary_search(vector<int> &a, int p) {
  if (a.size() == 0) return 0;
  if (a[0] > p) return 0;
  int ac = 0;
  int wa = a.size();
  while (wa - ac != 1) {
    int wj = ((ll)ac + wa) / 2;
    if (a[wj] <= p) {
      ac = wj;
    } else {
      wa = wj;
    }
  }
  return ac + 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> b(n + 1);
  rep(i, n) { b[a[i]].push_back(i); }

  int q;
  cin >> q;

  rep(i, q) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;

    int r_cnt = binary_search(b[x], r);
    int l_cnt = binary_search(b[x], l - 1);
    cout << r_cnt - l_cnt << endl;
  }
}