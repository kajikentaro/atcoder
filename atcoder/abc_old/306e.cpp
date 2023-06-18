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

signed main() {
  int n, k, q;
  cin >> n >> k >> q;

  multiset<int> no1;
  multiset<int, greater<int>> no2;
  rep(i, k) { no1.emplace(0); }
  rep(i, n - k + 1) { no2.emplace(0); }

  vector<int> a(n);
  int ans = 0;
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    x--;

    int before = a[x];
    int after = a[x] = y;

    int no2_edge = *no2.begin();
    if (no2.count(before)) {
      no2.erase(no2.find(before));
    } else if (no1.count(before)) {
      no1.erase(no1.find(before));
      ans -= before;

      no1.emplace(no2_edge);
      ans += no2_edge;
      no2.erase(no2.find(no2_edge));
    }

    int no1_edge = *no1.begin();
    if (no1_edge < after) {
      no1.erase(no1.find(no1_edge));
      ans -= no1_edge;
      no1.emplace(after);
      ans += after;
      no2.emplace(no1_edge);
    } else {
      no2.emplace(after);
    }
    cout << ans << endl;
  };
}