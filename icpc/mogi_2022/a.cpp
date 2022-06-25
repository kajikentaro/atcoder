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
int func() {
  int n;
  cin >> n;
  if (n == 0) return false;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  int ans = 0;
  rep(i, n) {
    int start;
    int s_ans = 1;
    for (int j = i; j < n; j++) {
      if (j == i) {
        start = a[j];
        continue;
      }
      if (start + 1 == a[j]) {
        s_ans++;
        start = a[j];
      } else {
        break;
      }
    }
    chmax(ans, s_ans);
  }
  cout << ans << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}