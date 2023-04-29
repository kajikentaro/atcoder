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

  priority_queue<int, vector<int>, greater<int>> wait;
  priority_queue<int, vector<int>, greater<int>> accept;
  set<int> done;

  rep(i, n) wait.emplace(i);

  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      accept.emplace(wait.top());
      wait.pop();
    }
    if (t == 2) {
      int x;
      cin >> x;
      x--;
      done.emplace(x);
    }
    if (t == 3) {
      while (1) {
        int candidate = accept.top();
        if (done.count(candidate)) {
          accept.pop();
          continue;
        } else {
          cout << candidate + 1 << endl;
          break;
        }
      }
    }
  }
}