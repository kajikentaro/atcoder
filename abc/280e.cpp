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
using mint = modint998244353;
using P = pair<int, int>;

// overflowに注意
mint cache2 = 0;
int n_cache2 = -1;
int r_cache2 = -1;
mint comb2(int n, int r) {
  if (n_cache2 + 1 == n && r_cache2 - 1 == r) {
    mint ans = cache2;
    ans *= n_cache2 + 1;
    ans /= n_cache2 - r_cache2 + 1;
    ans /= n_cache2 - r_cache2 + 2;
    ans *= r_cache2;
    cache2 = ans;
    return ans;
  }

  mint ans = 1;
  rep(i, r) {
    ans *= (n - i);
    ans /= (r - i);
  }
  cache2 = ans;
  n_cache2 = n;
  r_cache2 = r;
  return ans;
}

// overflowに注意
mint cache = 0;
int n_cache = -1;
int r_cache = -1;
mint comb(int n, int r) {
  if (n_cache + 1 == n && r_cache - 1 == r) {
    mint ans = cache;
    ans *= n_cache + 1;
    ans /= n_cache - r_cache + 1;
    ans /= n_cache - r_cache + 2;
    ans *= r_cache;
    cache = ans;
    return ans;
  }

  mint ans = 1;
  rep(i, r) {
    ans *= (n - i);
    ans /= (r - i);
  }
  cache = ans;
  n_cache = n;
  r_cache = r;
  return ans;
}

signed main() {
  int n, p;
  cin >> n >> p;

  mint bonus_p = (mint)p / 100;
  mint normal_p = (mint)(100 - p) / 100;
  mint ans = 0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    {
      // just n
      mint ans_tmp = 0;
      int bonus_cnt = n - i;
      int normal_cnt = i - bonus_cnt;
      ans_tmp += bonus_p.pow(bonus_cnt) * normal_p.pow(normal_cnt) *
                 comb(i, bonus_cnt);
      ans += ans_tmp * i;
    }
    {
      // n + 1
      mint ans_tmp = 0;
      int bonus_cnt = (n + 1) - i;
      if (bonus_cnt > i) continue;
      int normal_cnt = i - bonus_cnt;
      ans_tmp += bonus_p.pow(bonus_cnt) * normal_p.pow(normal_cnt) *
                 comb2(i - 1, bonus_cnt - 1);
      ans += ans_tmp * i;
    }
  }

  cout << ans.val() << endl;
}