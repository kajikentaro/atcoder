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
  int n;
  cin >> n;
  vector<int> a(n);
  ll all_sum = 0;
  rep(i, n) cin >> a[i];
  rep(i, n) all_sum += a[i];
  if (all_sum % 10) {
    cout << "No" << endl;
    return 0;
  }
  ll target = all_sum / 10;
  ll start = 0;
  ll last = 0;
  ll sum = a[0];
  while (last - start + 1 <= n && start <= n - 1) {
    if (sum == target) {
      cout << "Yes" << endl;
      return 0;
    }
    if (sum < target) {
      last++;
      sum += a[last % n];
    }
    if (target < sum) {
      sum -= a[start % n];
      start++;
    }
  }
  cout << "No" << endl;
  return 0;
}