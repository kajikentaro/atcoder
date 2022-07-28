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
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n) rep(j, n) {
    char input;
    cin >> input;
    if (i == j) continue;
    if (input == 'W') a[i][j] = 1;
    if (input == 'L') a[i][j] = -1;
    if (input == 'D') a[i][j] = 0;
  }
  rep(i, n) rep(j, n) {
    if (j == i) continue;
    if (a[i][j] == -a[j][i]) continue;
    cout << "incorrect" << endl;
    return 0;
  }
  cout << "correct" << endl;
}