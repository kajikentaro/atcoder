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

template <typename T>
struct BIT {
  int n;
  vector<T> bit;
  BIT(int n) : n(n + 1), bit(n + 1, 0) {}
  void add(int p, T x) {
    // bitは本来は1-indexだが使いやすさのため0-indexにする
    assert(0 <= p && p <= n - 1);
    p++;

    // (i&-1)で末尾の1を求める
    for (int i = p; i < n; i += (i & -i)) {
      bit[i] += x;
    }
  }
  T sum(int p) {
    assert(0 <= p && p <= n - 1);
    p++;

    T s(0);
    for (int i = p; i > 0; i -= (i & -i)) {
      s += bit[i];
    }
    return s;
  }
};

void insert_all(BIT<int> &bit, const vector<int> &input) {
  for (auto i : input) {
    bit.add(i, 1);
  }
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) { cin >> a[i][j]; }
  }

  vector<pair<int, pair<int, int>>> tmp(n * m);
  rep(i, n) {
    rep(j, m) {
      pair<int, pair<int, int>> t;
      t.first = a[i][j];
      t.second.first = i;
      t.second.second = j;
      tmp[m * i + j] = t;
    }
  }
  sort(tmp.begin(), tmp.end());

  int cnt = 0;
  for (auto t : tmp) {
    a[t.second.first][t.second.second] = cnt;
    cnt++;
  }

  BIT<int> bit(n * m);

  insert_all(bit, a[n - 1]);
  ll ans = 0;
  for (int i = n - 2; i >= 0; i--) {
    rep(j, m) {
      int now = a[i][j];
      int now_ans = bit.sum(now);

      int all_line_cnt = n - i - 1;
      int ans_tmp = now_ans + (all_line_cnt * 1) + (all_line_cnt * j);
      ans += ans_tmp;
    }
    insert_all(bit, a[i]);
  };
  cout << ans << endl;
}