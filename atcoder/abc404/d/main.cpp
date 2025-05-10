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

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> costs(n);
  rep(i, n) cin >> costs[i];

  vector<vector<int>> zoos(n);
  {
    rep(anim_id, m) {
      int anim_num;
      cin >> anim_num;
      rep(j, anim_num) {
        int zoo_id;
        cin >> zoo_id;
        zoo_id--;
        zoos[zoo_id].push_back(anim_id);
      }
    }
  }

  function<ll(int, int, vector<int> &)> dfs;
  dfs = [&](int zoo_id, int cost, vector<int> &anims) {
    if (zoo_id == n) {
      for (auto a : anims) {
        if (a < 2) return (ll)1e18;
      }
      return cost;
    }

    ll res = 1e18;
    // if 0
    chmin(res, dfs(zoo_id + 1, cost, anims));

    // if 1
    {
      for (auto anim : zoos[zoo_id]) {
        anims[anim]++;
      }
      chmin(res, dfs(zoo_id + 1, cost + costs[zoo_id], anims));
      for (auto anim : zoos[zoo_id]) {
        anims[anim]--;
      }
    }

    // if 2
    {
      for (auto anim : zoos[zoo_id]) {
        anims[anim] += 2;
      }
      chmin(res, dfs(zoo_id + 1, cost + costs[zoo_id] * 2, anims));
      for (auto anim : zoos[zoo_id]) {
        anims[anim] -= 2;
      }
    }

    return res;
  };

  vector<int> anims_count(m);
  int ans = dfs(0, 0, anims_count);

  cout << ans << endl;

  ;
}