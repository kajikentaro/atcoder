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

struct Eratosthenes {
  vector<bool> isprime;
  // minfactor[i] = p: 整数iは素数pで割り切れる(pは素数の中で最小)
  vector<int> minfactor;

  // 初期化: O(N log(N))
  Eratosthenes(int N) : isprime(N + 1, true), minfactor(N + 1, -1) {
    isprime[1] = false;
    minfactor[1] = 1;

    for (int p = 2; p <= N; ++p) {
      if (!isprime[p]) continue;

      minfactor[p] = p;

      for (int q = p * 2; q <= N; q += p) {
        isprime[q] = false;
        if (minfactor[q] == -1) minfactor[q] = p;
      }
    }
  }

  // 素因数分解: O(log(n))
  // - pair{素因子, 指数} の vector を返す
  vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    while (n > 1) {
      int p = minfactor[n];
      int exp = 0;

      // n で割り切れる限り割る
      while (minfactor[n] == p) {
        n /= p;
        ++exp;
      }
      res.emplace_back(p, exp);
    }
    return res;
  }

  // 約数列挙: n<10^9の範囲で1344回の計算
  vector<int> divisors(int n) {
    vector<int> res({1});

    auto pf = factorize(n);

    for (auto p : pf) {
      int s = (int)res.size();
      for (int i = 0; i < s; ++i) {
        int v = 1;
        for (int j = 0; j < p.second; ++j) {
          v *= p.first;
          res.push_back(res[i] * v);
        }
      }
    }
    return res;
  }
};

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  Eratosthenes er(*max_element(a.begin(), a.end()));

  map<int, int> fact;
  rep(i, n) {
    auto res = er.factorize(a[i]);

    for (auto &r : res) {
      chmax(fact[r.first], r.second);
    }
  }

  mint result = 1;
  for (auto &f : fact) {
    result *= (mint(f.first)).pow(f.second);
  }

  mint ans = 0;
  rep(i, n) { ans += result / a[i]; }

  cout << ans.val() << endl;
}
