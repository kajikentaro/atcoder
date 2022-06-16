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
double get_dist(P a, P b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> light(k);
  rep(i, k) {
    cin >> light[i];
    light[i]--;
  }
  vector<P> pos(n);
  rep(i, n) cin >> pos[i].first >> pos[i].second;

  vector<double> smaller_dist(n, 1e11);
  rep(ki, k) rep(ni, n) {
    double dist = get_dist(pos[ni], pos[light[ki]]);
    chmin(smaller_dist[ni], dist);
  }

  double ans = *max_element(smaller_dist.begin(), smaller_dist.end());
  printf("%.6lf\n", ans);
}