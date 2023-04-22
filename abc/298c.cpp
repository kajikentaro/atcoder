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
  int n, q;
  cin >> n >> q;

  vector<multiset<int>> box(n);
  map<int, set<int>> card;
  rep(_, q) {
    int t;
    cin >> t;
    switch (t) {
      case 1:
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        box[j].insert(i);
        card[i].insert(j);
        break;
      case 2:
        cin >> i;
        i--;
        for (auto b : box[i]) {
          cout << b + 1 << " ";
        }
        cout << endl;
        break;
      case 3:
        cin >> i;
        i--;
        for (auto b : card[i]) {
          cout << b + 1 << " ";
        }
        cout << endl;
        break;
    }
  }
}