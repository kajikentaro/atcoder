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
  string ss;
  cin >> ss;

  int A = 0;
  int T = 0;
  rep(i, n) {
    if (ss[i] == 'A') A++;
    if (ss[i] == 'T') T++;
  }

  if (A == T) {
    int A2 = 0;
    int T2 = 0;
    rep(i, n) {
      if (A2 == A) {
        cout << "A" << endl;
        return 0;
      }
      if (T2 == T) {
        cout << "T" << endl;
        return 0;
      }
      if (ss[i] == 'A') A2++;
      if (ss[i] == 'T') T2++;
    }
  }

  if (A < T) {
    cout << "T" << endl;
  } else {
    cout << "A" << endl;
  }
}