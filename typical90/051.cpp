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

vector<vector<ll>> exhaustive_search(vector<ll> item) {
  ll n = item.size();
  vector<vector<ll>> ans(n + 1);
  for (ll i = 0; i < (1 << n); i++) {
    ll sum = 0;
    ll select_cnt = 0;
    for (ll j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        select_cnt++;
        sum += item[j];
      }
    }
    ans[select_cnt].push_back(sum);
  }
  return ans;
}

int main() {
  ll n, k, p;
  cin >> n >> k >> p;
  vector<ll> item(n);
  rep(i, n) cin >> item[i];

  auto half_itr = item.begin() + n / 2;
  vector<vector<ll>> first_half =
      exhaustive_search(vector<ll>(item.begin(), half_itr));
  vector<vector<ll>> second_half =
      exhaustive_search(vector<ll>(half_itr, item.end()));

  for (auto &v : first_half) {
    sort(v.begin(), v.end());
  }
  for (auto &v : second_half) {
    sort(v.begin(), v.end());
  }

  ll ans = 0;
  rep(i, first_half.size()) rep(j, first_half[i].size()) {
    ll first = first_half[i][j];
    if (k - i < 0 || k - i >= second_half.size()) continue;
    vector<ll> &pair_list = second_half[k - i];
    if (pair_list.size() == 0) continue;
    if (pair_list[0] + first > p) continue;

    int ac = 0;
    int wa = pair_list.size();
    while (wa - ac != 1) {
      int wj = (ac + wa) / 2;

      ll wj_val = first + pair_list[wj];
      if (wj_val <= p) {
        ac = wj;
      } else {
        wa = wj;
      }
    }
    ans += (ac + 1);
  }
  cout << ans << endl;
}