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
ll next(ll now_a, ll m) {
  now_a *= now_a;
  now_a %= m;
  return now_a;
}
int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  vector<ll> to_idx(m + 10, -1);

  ll now_a = x;
  ll loop_start_idx = n;
  ll loop_size = -1;

  rep(i, n) {
    if (to_idx[now_a] == -1) {
      to_idx[now_a] = i;
      now_a = next(now_a, m);
    } else {
      loop_start_idx = to_idx[now_a];
      loop_size = i - loop_start_idx;
      break;
    }
  }

  ll loop_time = (n - loop_start_idx) / loop_size;
  ll loop_surplus = (n - loop_start_idx) % loop_size;

  ll prefix_sum = 0;
  now_a = x;
  rep(i, loop_start_idx) {
    prefix_sum += now_a;
    now_a = next(now_a, m);
  }

  ll loop_sum = 0;
  ll suffix_sum = 0;
  rep(i, loop_size) {
    loop_sum += now_a;
    now_a = next(now_a, m);

    if (i == loop_surplus - 1) {
      suffix_sum = loop_sum;
    }
  }

  ll ans = prefix_sum;
  ans += loop_sum * loop_time;
  ans += suffix_sum;

  cout << ans << endl;
}