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
vector<string> s_list;
int n;
bool is_unique(string target, int start, int last) {
  set<string> can;
  set<string> ng_can;
  for (auto s : s_list) can.insert(s);
  for (auto c : can) {
    // different length
    if (c.size() != target.size()) ng_can.insert(c);
  }
  rep(i, start) {
    // different first side
    for (auto c : can) {
      if (c[i] != target[i]) ng_can.insert(c);
    }
  }
  for (int i = last + 1; i < target.size(); i++) {
    for (auto c : can) {
      if (c[i] != target[i]) ng_can.insert(c);
    }
  }
  return can.size() - ng_can.size() == 1;
}
bool func() {
  cin >> n;
  if (n == 0) return false;

  s_list.resize(n);
  rep(i, n) cin >> s_list[i];

  ll ans = 0;
  for (auto s : s_list) {
    ll s_ans = 0;
    // max 30
    for (int start = 1; start < s.size() - 1; start++) {
      // max 30
      for (int last = start; last < s.size() - 1; last++) {
        if (is_unique(s, start, last)) {
          chmax(s_ans, (ll)last - start + 1);
        }
      }
    }
    ans += s_ans;
  }
  cout << ans << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}