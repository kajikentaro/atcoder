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
  string s;
  string t;
  cin >> s >> t;

  int s_at = 0;
  int t_at = 0;
  map<char, int> ma;
  for (auto ss : s) {
    if (ss == '@') s_at++;
    ma[ss]++;
  }
  for (auto tt : t) {
    if (tt == '@') t_at++;
    ma[tt]--;
  }

  string ok = "atcoder";
  for (auto m : ma) {
    if (m.first == '@') continue;
    if (m.second == 0) continue;
    bool isatcoder = false;
    for (auto o : ok) {
      if (o == m.first) isatcoder = true;
    }
    if (!isatcoder) {
      cout << "No" << endl;
      return 0;
    }

    if (m.second < 0) {
      s_at += m.second;
    } else {
      t_at -= m.second;
    }
  }

  if (t_at >= 0 && s_at >= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}