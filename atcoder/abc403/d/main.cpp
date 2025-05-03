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
  int n, d;
  cin >> n >> d;

  map<int, int> a_to_num;
  rep(i, n) {
    int a;
    cin >> a;
    a_to_num[a]++;
  }

  if (d == 0) {
    int ans = 0;
    for (auto [a, num] : a_to_num) {
      if (num == 1) continue;
      ans += num - 1;
    }
    cout << ans << endl;
    return 0;
  }

  map<int, int> a_to_deg;
  for (auto [a, num] : a_to_num) {
    for (auto ap : vector<int>{a - d, a + d}) {
      if (a_to_num.count(ap) == 0) continue;
      a_to_deg[ap] += num;
    }
  }

  map<int, set<int>, greater<int>> deg_to_a;
  for (auto [a, deg] : a_to_deg) {
    deg_to_a[deg].insert(a);
  }

  int ans = 0;
  while (deg_to_a.size()) {
    int a_deg = deg_to_a.begin()->first;
    if (a_deg <= 0) break;
    int a = *(deg_to_a[a_deg].begin());
    int a_num = a_to_num[a];

    ans += a_num;

    deg_to_a[a_deg].erase(a);
    if (deg_to_a[a_deg].size() == 0) {
      deg_to_a.erase(a_deg);
    }
    a_to_deg[a] = 0;

    for (auto ap : vector<int>{a - d, a + d}) {
      if (a_to_num.count(ap) == 0) continue;
      int deg_old = a_to_deg[ap];
      int deg_new = deg_old - a_num;
      a_to_deg[ap] = deg_new;
      deg_to_a[deg_old].erase(ap);
      deg_to_a[deg_new].insert(ap);

      if (deg_to_a[deg_old].size() == 0) {
        deg_to_a.erase(deg_old);
      }
    }
  }

  cout << ans << endl;
}