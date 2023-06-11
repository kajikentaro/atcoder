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

map<int, double> memo;
double sub(int n) {
  if (memo.count(n) != 0) return memo[n];

  if (n == 1) {
    return 3.5;
  }

  double next = sub(n - 1);
  double sum = 0;
  orep(i, 6) {
    if (next < i) {
      sum += i;
    } else {
      sum += next;
    }
  }
  return memo[n] = sum / 6;
}

signed main() {
  int n;
  cin >> n;

  printf("%.10lf\n", sub(n));
}