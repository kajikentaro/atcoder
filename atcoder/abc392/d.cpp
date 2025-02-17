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
  vector<map<int, int>> mas(n);
  vector<int> klist(n);
  vector<vector<int>> numbers(n);

  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int a;
      cin >> a;
      mas[i][a]++;
    }
    klist[i] = k;

    for (auto &a : mas[i]) {
      numbers[i].push_back(a.first);
    }
  }

  double ans = 0;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      int d1_total = klist[i];
      int d2_total = klist[j];

      double p_total = 0;
      for (auto &d : mas[i]) {
        int num = d.first;
        double p = mas[i][num] * mas[j][num];
        p_total += p;
      }
      p_total /= (d2_total * d1_total);

      chmax(ans, p_total);
    }
  }

  printf("%.10lf\n", ans);
}
