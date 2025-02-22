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
  int n, k;
  cin >> n >> k;

  vector<int> total(n);
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    total[i] = a + b + c;
  }

  vector<int> rank = total;
  sort(rank.begin(), rank.end());

  rep(i, n) {
    int score = total[i];
    int max = score + 300;

    auto itr = upper_bound(rank.begin(), rank.end(), max);
    int better = rank.end() - itr;

    if (better + 1 <= k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
