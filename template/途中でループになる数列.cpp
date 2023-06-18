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

struct Loop {
  vector<int> s;
  int prefix_len;
  int loop_len;

  set<int> used;
  // 1つずつインタラクティブにやる用
  bool add(int a) {
    s.push_back(a);
    if (used.count(a)) {
      return false;
    }
    calc();
    return true;
  }

  // 配列を用意しておいて一気に初期化する用
  void init(const vector<int> &_s) {
    s = _s;
    calc();
  }

  int get(int idx) {
    if (idx <= prefix_len - 1) {
      return s[idx];
    }
    int simplified_idx = (idx - prefix_len) % loop_len + prefix_len;
    return s[simplified_idx];
  }

 private:
  void calc() {
    rep(i, s.size()) {
      if (s[i] == s[s.size() - 1]) {
        prefix_len = i;
        loop_len = s.size() - prefix_len;
      }
    }
  }
};

signed main() {
  vector<int> s = {2, 7, 8, 9, 8, 9};

  Loop loop;
  for (auto a : s) {
    if (!loop.add(a)) break;
  }

  // output
  cout << loop.get(1) << endl;
  cout << loop.get(6) << endl;
}