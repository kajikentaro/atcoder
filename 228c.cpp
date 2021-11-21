#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  vector<int> p(n);
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    p[i] = a + b + c;
    mp[p[i]]++;
  }
  int rank_n = mp.size();
  vector<P> rank;
  for (auto m : mp) {
    rank.push_back(m);
  }
  sort(rank.rbegin(), rank.rend());
  vector<int> sum(rank_n);
  sum[0] = 0;
  rep(i, rank_n) {
    if (i == 0) continue;
    sum[i] = sum[i - 1] + rank[i].second;
  }
  rep(i, n) {
    int wa = -1;
    int ac = rank_n - 1;
    while (ac - wa != 1) {
      int wj = (ac + wa + 1) / 2;
      if (p[i] + 300 >= rank[wj].first) {
        ac = wj;
      } else {
        wa = wj;
      }
    }
    if (sum[ac] + 1 <= k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}