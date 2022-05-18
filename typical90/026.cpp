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
vector<int> used;
vector<vector<int>> path;
void dfs(int point, int depth) {
  if (used[point] != -1) return;
  used[point] = depth;
  for (auto p : path[point]) {
    dfs(p, depth + 1);
  }
}
int main() {
  int n;
  cin >> n;
  used.resize(n, -1);
  path.resize(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  dfs(0, 0);
  vector<int> ans1;
  vector<int> ans2;
  rep(i, n) {
    if (used[i] % 2) {
      ans1.push_back(i);
    } else {
      ans2.push_back(i);
    }
  }
  if (ans1.size() >= n / 2) {
    swap(ans1, ans2);
  }
  rep(i, n / 2) { cout << ans2[i] + 1 << " "; }
  cout << endl;
}