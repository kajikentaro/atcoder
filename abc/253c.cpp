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
  int q;
  cin >> q;
  map<int, int> box;
  int ma = -1;
  int mi = -1;
  rep(i, q) {
    int t;
    cin >> t;
    switch (t) {
      case 1: {
        int x;
        cin >> x;
        box[x]++;
        break;
      }
      case 2: {
        int x, c;
        cin >> x >> c;
        box[x] -= c;
        if (box[x] <= 0) box.erase(x);
        break;
      }
      case 3:
        int mi = box.begin()->first;
        int ma = box.rbegin()->first;
        cout << ma - mi << endl;
        break;
    }
  }
}