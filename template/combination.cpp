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

// overflowに注意
// 非推奨.下の方を使ったほうが良いかも
ll comb(int n, int r) {
  ll i = 1;
  ll k = r > n - r ? n - r : r, count;
  if (k < 0) return 0;
  std::list<ll> list;
  std::list<ll>::iterator it;
  for (count = 2; count <= k; ++count) list.push_back(count);
  for (count = n; count > n - k; --count) {
    i *= count;
    for (it = list.begin(); it != list.end();) {
      if (!(i % *it)) {
        i /= *it;
        it = list.erase(it);
      } else
        ++it;
    }
  }
  return i;
}

// パスカルの三角形
vector<vector<mint>> pascal;
mint comb2(int n, int r) {
  if (pascal.size() == 0) {
    // init
    int MAX_N = 1e4 + 10;  // intに変えてもこれが限界
    pascal.resize(MAX_N + 1, vector<mint>(MAX_N + 1));

    for (int i = 0; i <= n; i++) {
      pascal[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]);
      }
    }
  }
  return pascal[n][r];
}

int main() {
  cout << comb(1e3, 5e2) << endl;
  ;
}