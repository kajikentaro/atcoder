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

int d = 1e9;

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);

  int sum = 0;
  rep(i, n + 1) {
    if (i < k) {
      a[i] = 1;
    } else {
      a[i] = sum;
    }

    sum += a[i];
    sum %= d;
    if (i - k >= 0) sum -= a[i - k];
    sum += d;
    sum %= d;
  };
  cout << a[n] << endl;
}