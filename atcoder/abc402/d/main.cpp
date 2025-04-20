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
using mint = modint1000000007;
using P = pair<int, int>;

int c2(int m) { return m * (m - 1) / 2; }

signed main() {
  int n, m;
  cin >> n >> m;

  map<P, int> ma;

  rep(i, m) {
    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);
    // now it's a < b

    int diff = b - a;
    if (diff >= 3) {
      int desc = diff % 2 == 0 ? (diff - 2) / 2 : (diff - 1) / 2;
      a += desc;
      b -= desc;
    }

    ma[P(a, b)]++;
  };

  {
    map<P, int> ma2;
    for (auto [p, cnt] : ma) {
      auto [a, b] = p;

      if (n % 2 == 0) {
        int a2 = (a + n / 2) % n;
        if (a2 == 0) a2 = n;
        int b2 = (b + n / 2) % n;
        if (b2 == 0) b2 = n;
        if (a2 > b2) swap(a2, b2);

        if (a2 < a) {
          swap(a, a2);
          swap(b, b2);
        }
      } else {
        int N = n * 2;
        int A = a * 2;
        int B = b * 2;
        int A2 = (A + N / 2) % N;
        int B2 = (B + N / 2) % N;
        if (A2 > B2) swap(A2, B2);

        int diff = ((B2 - A2) + N + N) % N;
        int C = (A2 + B2) / 2;
        if (diff == 2) {
          A2 = C - 2;
          B2 = C + 2;
        } else {
          A2 = C - 1;
          B2 = C + 1;
        }
        A2 += N;
        A2 %= N;
        B2 += N;
        B2 %= N;

        if (A2 == 0) A2 = N;
        if (B2 == 0) B2 = N;

        int a2 = A2 / 2;
        int b2 = B2 / 2;

        if (a2 > b2) swap(a2, b2);

        if (a2 < a) {
          swap(a, a2);
          swap(b, b2);
        }
      }

      ma2[P(a, b)] += cnt;
    }
    swap(ma, ma2);
  }

  int ans = c2(m);
  for (auto [tmp, cnt] : ma) {
    ans -= c2(cnt);
  }
  cout << ans << endl;
}
