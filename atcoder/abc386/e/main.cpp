#include <bits/stdc++.h>

#include <atcoder/all>
#define int long long
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

int n, k;
vector<int> a;
int ans = 0;

vector<int> sum;

void dfs(int idx, int remain, int val) {
  if (remain == 0) {
    chmax(ans, val);
    return;
  }

  int unselected = n - idx;
  if (unselected == remain) {
    int a = val ^ sum[idx];
    chmax(ans, a);
    return;
  } else {
    dfs(idx + 1, remain, val);
  }
  dfs(idx + 1, remain - 1, val ^ a[idx]);
}

signed main() {
  cin >> n >> k;
  a.resize(n);
  rep(i, n) cin >> a[i];

  sum.resize(n);
  rrep(i, n) {
    if (i == n - 1)
      sum[i] = a[i];
    else
      sum[i] = sum[i + 1] ^ a[i];
  }

  dfs(0, k, 0);

  cout << ans << endl;
}