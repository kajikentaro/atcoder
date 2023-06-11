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

ll func(const vector<ll> &x, ll t) {
  ll ans = 0;
  rep(i, x.size()) { ans += abs(x[i] - t); }
  return ans;
}

ll binary_search(const vector<ll> &x) {
  ll mi_idx = *min_element(x.begin(), x.end()) - 1;
  ll ma_idx = *max_element(x.begin(), x.end()) + 1;
  ll ce_idx;
  while (1) {
    ce_idx = (mi_idx + ma_idx) / 2;
    ll ce_mi_idx = ce_idx - 1;
    ll ce_ma_idx = ce_idx + 1;

    ll ce_val = func(x, ce_idx);
    ll ce_mi_val = func(x, ce_mi_idx);
    ll ce_ma_val = func(x, ce_ma_idx);

    if (ce_mi_val < ce_val && ce_val < ce_ma_val) {
      // 傾きが正のとき
      ma_idx = ce_idx;
    } else if (ce_ma_val < ce_val && ce_val < ce_mi_val) {
      // 傾きが負のとき
      mi_idx = ce_idx;
    } else {
      // 傾きが0のとき
      break;
    }
  }
  return func(x, ce_idx);
}
int main() {
  ll n;
  cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  rep(i, n) cin >> x[i] >> y[i];
  ll x_ans = binary_search(x);
  ll y_ans = binary_search(y);
  cout << x_ans + y_ans << endl;
}