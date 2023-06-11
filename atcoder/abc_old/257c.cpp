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
int main() {
  ll n;
  string s;
  cin >> n >> s;

  vector<ll> w(n);
  rep(i, n) cin >> w[i];

  vector<ll> child;
  vector<ll> adult;
  rep(i, n) {
    if (s[i] == '0') {
      child.push_back(w[i]);
    } else {
      adult.push_back(w[i]);
    }
  }
  sort(child.begin(), child.end());
  sort(adult.begin(), adult.end());

  ll ans = 0;
  for (auto t_origin : w) {
    {
      // t未満
      int t = t_origin;

      auto c_itr = lower_bound(child.begin(), child.end(), t);
      ll child_score = (c_itr - child.begin());

      auto a_itr = lower_bound(adult.begin(), adult.end(), t);
      ll adult_score = (adult.end() - a_itr);

      chmax(ans, child_score + adult_score);
    }
    {
      // t+1未満
      int t = t_origin + 1;

      auto c_itr = lower_bound(child.begin(), child.end(), t);
      ll child_score = (c_itr - child.begin());

      auto a_itr = lower_bound(adult.begin(), adult.end(), t);
      ll adult_score = (adult.end() - a_itr);

      chmax(ans, child_score + adult_score);
    }
  }
  cout << ans << endl;
}