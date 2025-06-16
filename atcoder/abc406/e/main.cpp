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

int count_keta(int n) {
  int count = 0;
  while (n > 0) {
    n /= 2;
    count++;
  }
  return count;
}

bool is_1(int n, int keta) { return (n << keta) & 1; }

std::string myto_string(int num) {
  std::string binary;
  while (num > 0) {
    binary = (num % 2 ? "1" : "0") + binary;
    num /= 2;
  }
  return binary;
}

ll solve() {
  ll n;
  int k;
  cin >> n >> k;
  string n_str = myto_string(n);
  int ns = count_keta(n);
  // dp[上からi桁目のとき][popcountがjであり][strictがkである]
  mint dp[ns + 2][k + 2][2] = {};
  dp[0][0][1] = 1;

  rep(keta, ns) {
    rep(now, k + 1) {
      // この桁を1にするか0にするか
      rep(entry, 2) {
        // 次のpopcount
        int next = (now + entry);

        dp[keta + 1][next][0] += dp[keta][now][0];
        if (entry == n_str[keta] - '0') {
          dp[keta + 1][next][1] += dp[keta][now][1];
        }
        if (entry < n_str[keta] - '0') {
          dp[keta + 1][next][0] += dp[keta][now][1];
        }
        if (entry > n_str[keta] - '0') continue;
      }
    }
  }
  ll ans = (dp[ns][k][1] + dp[ns][k][0] - 1).val();
  return ans;
}

signed main() {
  int t;
  cin >> t;
  rep(i, t) cout << solve() << endl;
}