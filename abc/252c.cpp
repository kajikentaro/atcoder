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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  int cnt[10] = {};
  rep(i, 10 * n) {
    int tmp[10] = {};
    rep(j, n) {
      int number = s[j][i % 10] - '0';
      if (tmp[number]) continue;
      cnt[number]++;
      tmp[number]++;
    }
    rep(j, 10) {
      if (cnt[j] == n) {
        cout << i << endl;
        return 0;
      }
    }
  }
}