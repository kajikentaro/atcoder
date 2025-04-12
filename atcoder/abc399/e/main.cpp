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

int solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  int ans = 0;
  // NGケース判定
  {
    vector<int> path(26, -1);
    rep(i, n) {
      int from = s[i] - 'a';
      int to = t[i] - 'a';

      if (path[from] == -1) {
        path[from] = to;

        if (from != to) {
          ans++;
        }

      } else {
        if (path[from] == to) continue;
        return -1;
      }
    }
  };

  scc_graph scc(26);
  rep(i, n) {
    int from = s[i] - 'a';
    int to = t[i] - 'a';

    scc.add_edge(from, to);
  }

  auto res = scc.scc();

  bool loop = false;
  for (auto re : res) {
    if (re.size() > 1) {
      ans++;
      loop = true;
    }
  }

  if (loop) {
    // char which is used in s
    set<char> used;
    for (auto se : s) {
      used.insert(se);
    }

    bool is_all_letters_used = used.size() == 26;
    if (is_all_letters_used) {
      return -1;
    }
  }

  return ans;
}

signed main() { cout << solve() << endl; }