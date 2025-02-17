// https://qiita.com/drken/items/3beb679e54266f20ab63#4-1-%E9%AB%98%E9%80%9F%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

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

int main() {
  ll SEARCH_MAX = 1e7 + 10;
  Eratosthenes er(SEARCH_MAX);
}
