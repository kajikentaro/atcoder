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
  int n3 = n * 3;
  map<int, int> dis;

  vector<P> res(n);
  rep(i, n) { res[i].second = i + 1; }
  rep(i, n3) {
    int a;
    cin >> a;
    dis[a]++;
    if (dis[a] == 2) {
      res[a - 1].first = i;
    }
  };

  sort(res.begin(), res.end());
  for (auto r : res) {
    cout << r.second << " ";
  }
  cout << endl;
}