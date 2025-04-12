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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  priority_queue<P> que;
  rep(i, n) { que.emplace(a[i], i); }

  int now = 1;
  int prev_score = 1e9;
  int prev_cnt = 0;
  vector<int> ans(n);
  while (que.size()) {
    auto [aa, i] = que.top();
    que.pop();

    if (aa != prev_score) {
      now += prev_cnt;
      prev_score = aa;
      prev_cnt = 0;
    }

    prev_cnt++;
    ans[i] = now;
  };

  for (auto aa : ans) {
    cout << aa << endl;
  }
}