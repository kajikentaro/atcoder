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
  map<int, int> x_list;
  map<int, int> y_list;
  rep(i, 3) {
    int x, y;
    cin >> x >> y;
    x_list[x]++;
    y_list[y]++;
  }
  for (auto x : x_list) {
    if (x.second == 1) {
      cout << x.first << " ";
    }
  }
  for (auto y : y_list) {
    if (y.second == 1) {
      cout << y.first << endl;
    }
  }
}
