#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  auto is_ac = [&](int wj) {
    map<int, int> a_map;
    rep(i, wj) { a_map[a[i]]++; }
    int min_kind = a_map.size();
    rep(i, n) {
      a_map[a[i]]--;
      if (a_map[a[i]] == 0) {
        a_map.erase(a[i]);
      }

      int idx = i + wj;
      if (idx >= n) break;
      a_map[a[idx]]++;

      chmin(min_kind, (int)a_map.size());
    }
    return min_kind <= k;
  };

  int ac = 0;
  int wa = n + 1;
  while (wa - ac != 1) {
    int wj = (ac + wa) / 2;
    if (is_ac(wj)) {
      ac = wj;
    } else {
      wa = wj;
    }
  }
  cout << ac << endl;
}