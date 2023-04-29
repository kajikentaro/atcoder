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

vector<ll> get_prime() {
  vector<ll> prime;
  ll SEARCH_MAX = 1e6 + 10;
  vector<bool> tmp(SEARCH_MAX);
  for (ll i = 2; i * i <= SEARCH_MAX; i++) {
    if (tmp[i] == true) continue;
    for (ll j = i * 2; j < SEARCH_MAX; j += i) {
      tmp[j] = true;
    }
  }
  rep(i, SEARCH_MAX) {
    if (i < 2) continue;
    if (tmp[i] == 0) prime.push_back(i);
  }

  return prime;
}

int main() {
  vector<ll> prime = get_prime();
  int m = prime.size();

  ll n;
  cin >> n;

  ll ans = 0;
  for (int ci = 2; ci < m; ci++) {
    ll c = prime[ci];
    ll c2 = c * c;

    // a^2 * b  <= n / c^2
    ll a2b_max = n / c2;
    if (a2b_max < 12) break;  // 枝切り

    for (int ai = 0; ai < m; ai++) {
      if (!(ai < ci - 1)) break;

      ll a = prime[ai];
      ll a2 = a * a;

      // a2 * b * c2 <= n
      // if (a2 > n / c2) continue;
      // b <= n / (a2 * c)
      ll b_max = n / (a2 * c2);
      if (!(a < b_max)) break;
      auto bi_itr = upper_bound(prime.begin(), prime.end(), b_max);
      int bi_max_tmp = bi_itr - prime.begin();
      int bi_max = min(bi_max_tmp - 1, ci - 1);

      ll ans_tmp = bi_max - ai;
      // assert(bi_max > ai);
      // assert(ai < ci);
      // assert(ai + ans_tmp < ci);
      // assert(prime[ai] < prime[bi_max]);
      // assert(prime[bi_max] < prime[ci]);
      // assert(prime[ai] * prime[ai] * prime[bi_max] * prime[ci] * prime[ci] <=
      //        n);
      ans += ans_tmp;
    }
  }

  cout << ans << endl;
}