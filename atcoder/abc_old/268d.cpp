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
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  if (n == 1 && s[0].size() <= 2) {
    cout << -1 << endl;
    return 0;
  }

  set<string> t;
  rep(i, m) {
    string tmp;
    cin >> tmp;
    t.emplace(tmp);
  }

  int ub_max, ub_min;
  {
    int sum = 0;
    for (auto ss : s) sum += ss.size();
    ub_max = 16 - (sum + (n - 1));
    ub_min = 3 - (sum + (n - 1));
    if (ub_max < 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<vector<int>> ubs;
  {
    vector<int> tmp;
    rep(i, ub_max) tmp.push_back(1);
    rep(i, n - 1) tmp.push_back(0);
    sort(tmp.begin(), tmp.end());

    do {
      vector<int> res;
      int idx = 0;
      int now = 0;
      for (auto t : tmp) {
        if (t == 1) now++;
        if (t == 0) {
          res.push_back(now);
          now = 0;
        }
      }
      ubs.push_back(res);
    } while (next_permutation(tmp.begin(), tmp.end()));
  }

  vector<string> u_template;
  {
    string tmp = "_";
    rep(i, 20) {
      u_template.push_back(tmp);
      tmp += "_";
    }
  }

  sort(s.begin(), s.end());
  do {
    for (auto u : ubs) {
      string now = "";
      rep(i, s.size()) {
        now += s[i];

        if (i != s.size() - 1) {
          now += u_template[u[i]];
        }
      }

      if (t.count(now) == 0) {
        assert(now.size() <= 16);
        assert(now.size() >= 3);
        cout << now << endl;
        return 0;
      }
    }
  } while (next_permutation(s.begin(), s.end()));
  cout << -1 << endl;
}
