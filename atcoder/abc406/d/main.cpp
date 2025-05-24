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
  int h, w, n;
  cin >> h >> w >> n;

  vector<set<P>> th(h);
  vector<set<P>> tw(w);

  rep(i, n) {
    int hi, wi;
    cin >> hi >> wi;
    hi--;
    wi--;
    th[hi].emplace(hi, wi);
    tw[wi].emplace(hi, wi);
  };

  int q;
  cin >> q;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int hi;
      cin >> hi;
      hi--;
      cout << th[hi].size() << endl;
      for (auto p : th[hi]) {
        tw[p.second].erase(p);
      }
      th[hi].clear();
    }
    if (t == 2) {
      int wi;
      cin >> wi;
      wi--;
      cout << tw[wi].size() << endl;
      for (auto p : tw[wi]) {
        th[p.first].erase(p);
      }
      tw[wi].clear();
    }
  }
}