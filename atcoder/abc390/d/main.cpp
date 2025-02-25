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

int n;
vector<ll> a;
vector<ll> groups;
set<ll> ans;
void dfs(int now) {
  if (now == n) {
    ll a = 0;
    for (auto &r : groups) {
      a ^= r;
    }
    ans.insert(a);
    return;
  }
  int gn = groups.size();

  rep(i, gn) {
    groups[i] += a[now];
    dfs(now + 1);
    groups[i] -= a[now];
  }

  {
    groups.push_back(a[now]);
    dfs(now + 1);
    groups.pop_back();
  }
}

signed main() {
  cin >> n;
  a.resize(n);
  rep(i, n) cin >> a[i];

  dfs(0);

  cout << ans.size() << endl;
}