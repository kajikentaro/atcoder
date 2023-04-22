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

int n;
bool isSame(vector<vector<int>> a, vector<vector<int>> b) {
  rep(i, n) rep(j, n) {
    if (a[i][j]) {
      if (b[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(n));

  rep(i, n) rep(j, n) { cin >> a[i][j]; }
  rep(i, n) rep(j, n) { cin >> b[i][j]; }

  auto rotate = [&]() {
    vector<vector<int>> tmp(n, vector<int>(n));
    rep(i, n) rep(j, n) { tmp[i][j] = a[n - 1 - j][i]; }
    swap(tmp, a);
  };

  if (isSame(a, b)) {
    cout << "Yes" << endl;
    return 0;
  }
  rotate();
  if (isSame(a, b)) {
    cout << "Yes" << endl;
    return 0;
  }
  rotate();
  if (isSame(a, b)) {
    cout << "Yes" << endl;
    return 0;
  }
  rotate();
  if (isSame(a, b)) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
