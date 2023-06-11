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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> pos(k);
  rep(i, k) cin >> pos[i];

  rep(i, q) {
    int l;
    cin >> l;
    l--;
    if (pos[l] == n) continue;
    int new_pos = pos[l] + 1;
    if (l + 1 <= k - 1 && pos[l + 1] == new_pos) continue;
    pos[l] = new_pos;
  }
  rep(i, k) cout << pos[i] << " ";
  cout << endl;
}