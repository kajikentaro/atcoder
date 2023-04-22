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
using mint = modint998244353;
using P = pair<int, int>;

int main() {
  int q;
  cin >> q;

  mint a = 1;
  queue<int> b;
  b.emplace(1);
  rep(_, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      a *= 10;
      a += x;
      b.emplace(x);
    }
    if (t == 2) {
      int keta = b.size();
      int head = b.front();
      a -= mint(head) * mint(10).pow(keta - 1);
      b.pop();
    }
    if (t == 3) {
      cout << a.val() << endl;
    }
  }
}