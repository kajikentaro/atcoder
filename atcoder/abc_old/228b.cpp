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
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> b(n);
  int ans = 1;
  int new_target = x;
  b[x] = 1;
  while (1) {
    new_target = a[new_target];
    if (b[new_target]) break;
    b[new_target] = 1;
    ans++;
  }
  cout << ans << endl;
}