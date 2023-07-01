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

struct Grid {
  int h, w;
  vector<string> s;

  char get(int hi, int wi, int m_hi, int m_wi) {
    int r_hi = hi - m_hi;
    int r_wi = wi - m_wi;
    if (r_hi < 0 || r_wi < 0 || r_hi >= h || r_wi >= w) return '.';
    return s[r_hi][r_wi];
  }
};

struct Master {
  Grid &a, &b;
  int a_hi_m, a_wi_m;
  int b_hi_m, b_wi_m;

  // echo hoge echo hoge echo hoge echo hoge echo hoge echo hoge echo hoge echo
  // hoge echo hoge echo hoge
  Master(int a_hi, int a_wi, int b_hi, int b_wi, Grid &a, Grid &b)
      : a_hi_m(a_hi), a_wi_m(a_wi), b_hi_m(b_hi), b_wi_m(b_wi), a(a), b(b) {}

  char get(int hi, int wi) {
    char av = a.get(hi, wi, a_hi_m, a_wi_m);
    char bv = b.get(hi, wi, b_hi_m, b_wi_m);

    if (av == '#' && bv == '#') {
      return '#';
    }
    if (av == '#') {
      return '#';
    }
    if (bv == '#') {
      return '#';
    }
    return '.';
  }
};

Grid input() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  int hi_min = 1e9;
  int hi_max = 0;
  int wi_min = 1e9;
  int wi_max = 0;
  rep(hi, h) rep(wi, w) {
    if (s[hi][wi] == '.') continue;
    chmin(hi_min, hi);
    chmin(wi_min, wi);

    chmax(hi_max, hi);
    chmax(wi_max, wi);
  }

  vector<string> s2(s.begin() + hi_min, s.begin() + hi_max + 1);
  h = s2.size();
  rep(i, h) {
    s2[i] = string(s2[i].begin() + wi_min, s2[i].begin() + wi_max + 1);
  }
  w = s2[0].size();

  Grid res = {h, w, s2};
  return res;
}

signed main() {
  Grid a = input();
  Grid b = input();
  Grid c = input();

  rep(a_hi, c.h) {
    rep(a_wi, c.w) {
      rep(b_hi, c.h) {
        rep(b_wi, c.w) {
          Master master(a_hi, a_wi, b_hi, b_wi, a, b);

          if (a_hi + a.h > c.h) continue;
          if (a_wi + a.w > c.w) continue;
          if (b_hi + b.h > b.h) continue;
          if (b_wi + b.w > c.w) continue;

          bool is_ok = true;
          rep(c_hi, c.h) {
            rep(c_wi, c.w) {
              if (master.get(c_hi, c_wi) != c.s[c_hi][c_wi]) {
                is_ok = false;
              }
            }
          }
          if (is_ok) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;
}
