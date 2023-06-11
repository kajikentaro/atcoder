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
int main() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<P> a(n);
  vector<P> b(n);
  vector<P> sum(n);
  rep(i, n) cin >> a[i].first, a[i].second = i + 1;
  rep(i, n) cin >> b[i].first, b[i].second = i + 1;
  rep(i, n) sum[i].first = a[i].first + b[i].first, sum[i].second = i + 1;

  auto cmp = [](const P &a, const P &b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first > b.first;
  };
  sort(a.begin(), a.end(), cmp);
  sort(b.begin(), b.end(), cmp);
  sort(sum.begin(), sum.end(), cmp);

  vector<int> used(n + 10);
  vector<int> ans;

  auto select = [&](vector<P> humans, int max) {
    int cnt = 0;
    if (max == 0) return;
    for (auto h : humans) {
      if (used[h.second]) continue;
      used[h.second] = 1;
      cnt++;
      ans.push_back(h.second);
      if (cnt == max) return;
    }
  };

  select(a, x);
  select(b, y);
  select(sum, z);

  sort(ans.begin(), ans.end());
  for (auto a : ans) {
    cout << a << endl;
  }
}