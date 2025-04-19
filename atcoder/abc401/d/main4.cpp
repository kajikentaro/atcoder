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
struct Cnt {
  int o = 0;
  int q = 0;
  int dot = 0;
};

Cnt count(string s) {
  Cnt cnt;
  rep(i, s.size()) {
    if (s[i] == 'o') {
      cnt.o++;
    }
    if (s[i] == '?') {
      cnt.q++;
    }
    if (s[i] == '.') {
      cnt.dot++;
    }
  }
  return cnt;
}

signed main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  rep(i, n) {
    if (s[i] == 'o') {
      if (i - 1 >= 0) s[i - 1] = '.';
      if (i + 1 < n) s[i + 1] = '.';
    }
  }

  vector<int> qs;
  int q_cnt = 0;
  rep(i, n) {
    if (s[i] == '?') {
      q_cnt++;
    } else {
      if (q_cnt > 0) {
        qs.push_back(q_cnt);
      }
      q_cnt = 0;
    }
  }
  if (q_cnt > 0) {
    qs.push_back(q_cnt);
  }

  int sum_avail = 0;
  for (auto q : qs) {
    int avail = (q + 1) / 2;
    sum_avail += avail;
  }

  if (qs.size() == 0) {
    cout << s << endl;
    return 0;
  }

  Cnt cnt = count(s);
  if (cnt.o + sum_avail == k) {
    int qsi = 0;
    bool now_should_replace = qs[qsi] % 2 == 1;
    bool now_using = false;
    rep(i, n) {
      if (s[i] == '?') {
        now_using = true;
        if (now_should_replace) {
          s[i] = 'o';
          if (i + 1 < n) s[i + 1] = '.';
          i++;
          continue;
        } else {
          i += qs[qsi] - 1;
        }
      } else {
        if (now_using) {
          now_using = false;
          qsi++;
          if (qsi < qs.size()) now_should_replace = qs[qsi] % 2 == 1;
        }
      }
    }
  };

  if (k == 0) {
    rep(i, n) {
      if (s[i] == '?') {
        s[i] = '.';
      }
    }
  }

  cout << s << endl;
}