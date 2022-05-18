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

int func(int n) {
  int n_backup = n;
  int k = 0;
  while (n) {
    k += n % 10;
    n /= 10;
  }
  return (n_backup + k) % (int)1e5;
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> phenomenon(1e5 + 10, -1);

  int ni = n;

  phenomenon[n] = 0;

  int dest;
  int start;
  orep(i, k) {
    ni = func(ni);
    if (phenomenon[ni] != -1) {
      start = phenomenon[ni];
      dest = i;
      break;
    }
    phenomenon[ni] = i;
    if (i == k) {
      cout << ni << endl;
      return 0;
    }
  }

  ll loop = dest - start;

  ll k2 = (k - start) % loop + start;

  rep(i, k2) { n = func(n); }
  cout << n << endl;
}