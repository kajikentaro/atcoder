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
vector<bool> used;
vector<vector<int>> sorted_x;
vector<vector<int>> path;
vector<int> x;
void dfs(int p) {
  if (used[p]) return;
  used[p] = true;
  vector<int> children_x;
  for (int np : path[p]) {
    dfs(np);
    for (int nx : sorted_x[np]) {
      children_x.push_back(nx);
    }
  }
  children_x.push_back(x[p]);
  sort(children_x.rbegin(), children_x.rend());

  rep(i, 20) {
    if (children_x.size() == i) break;
    sorted_x[p].push_back(children_x[i]);
  }
}
int main() {
  int n, q;
  cin >> n >> q;
  used.resize(n, false);
  sorted_x.resize(n);
  x.resize(n);
  rep(i, n) cin >> x[i];
  path.resize(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  dfs(0);
  rep(i, q) {
    int v, k;
    cin >> v >> k;
    cout << sorted_x[v - 1][k - 1] << endl;
  }
}