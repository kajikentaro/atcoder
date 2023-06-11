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
using mint = modint998244353;
using P = pair<int, int>;

int main() {
  ll n;
  vector<ll> k;
  cin >> n;
  for (ll i = 2; i * i <= n;) {
    if (n % i == 0) {
      k.push_back(i);
      n /= i;
      continue;
    } else {
      i++;
    }
  }
  if (n != 1) k.push_back(n);

  map<ll, ll> ma;
  for (auto kk : k) {
    ma[kk]++;
  }

  ll tmp1 = ma.size();
  ll tmp = ma[2] + ma[3] + ma[5];
  if (tmp1 != tmp) {
    cout << 0 << endl;
  }

  mint ans = 1;
  while (1) {
    map<ll, ll> now = ma;
    while (1) {
      mint tmp_ans = 1;

      for (auto n : now) {
        tmp_ans *= n.second;
      }

      if (now[2] >= 1 && now[3] >= 1) {
        now[2] -= 1;
        now[3] -= 1;
        now[6]++;
      }
    }
    if (now[2] >= 2) {
      now[2] -= 2;
      now[4]++;
    }
  }
}