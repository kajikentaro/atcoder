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
  int n;
  cin >> n;
  vector<P> blue(n);
  vector<P> red(n);
  rep(i, n) cin >> red[i].first >> red[i].second;
  rep(i, n) cin >> blue[i].first >> blue[i].second;

  mf_graph<ll> graph(2 * n + 2);
  rep(bi, n) rep(ri, n) {
    if (red[ri].first < blue[bi].first && red[ri].second < blue[bi].second) {
      graph.add_edge(ri, bi + n, 1);
    }
  }
  rep(i, n) graph.add_edge(2 * n, i, 1);
  rep(i, n) graph.add_edge(i + n, 2 * n + 1, 1);

  vector<bool> res = graph.min_cut(2 * n);
  ll ans = 0;
  rep(i, n) {
    if (res[i]) ans++;
  }
  cout << ans << endl;
}