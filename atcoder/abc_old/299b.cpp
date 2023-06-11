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
  int n, t;
  cin >> n >> t;

  vector<int> score(n);
  vector<int> color(n);
  rep(i, n) cin >> color[i];
  rep(i, n) cin >> score[i];

  // color, vector<int>
  map<int, vector<P>> ma;
  rep(i, n) { ma[color[i]].push_back(P{score[i], i}); }

  vector<P> qualified;
  if (ma[t].size() > 0) {
    qualified = ma[t];
  } else {
    qualified = ma[color[0]];
  }

  sort(qualified.rbegin(), qualified.rend());

  cout << qualified[0].second + 1 << endl;
}