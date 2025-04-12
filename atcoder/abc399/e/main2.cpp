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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  {
    // 重複検知
    map<char, char> to;
    rep(i, n) {
      if (to.count(s[i]) == 0) {
        to[s[i]] = t[i];
      } else {
        if (to[s[i]] == t[i]) {
          // ok
        } else {
          // ng
          cout << -1 << endl;
          return 0;
        }
      }
    };
  }

  int ans = 0;
  scc_graph scc(26);
  vector<int> used(26);
  rep(i, n) {
    int s_no = s[i] - 'a';
    int t_no = t[i] - 'a';
    if (s[i] == t[i]) continue;
    if (used[s_no]) continue;
    used[s_no] = 1;
    scc.add_edge(s_no, t_no);
    ans++;
  };

  auto sc = scc.scc();
  for (auto ss : sc) {
    if (ss.size() > 1) ans++;
    if (ss.size() == 26) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans << endl;
}