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

string donyoku(string s, int n) {
  rep(i, n) {
    if (s[i] == '?') {
      bool right = true;
      if (i + 1 < n && s[i + 1] == 'o') {
        right = false;
      }

      bool left = true;
      if (i - 1 >= 0 && s[i - 1] == 'o') {
        left = false;
      }
      if (right && left) {
        if (i + 1 < n) s[i + 1] = '.';
        if (i - 1 >= 0) s[i - 1] = '.';
        s[i] = 'o';
      }
    }
  }
  return s;
}

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

  string don1 = donyoku(s, n);
  string s_rev = s;
  reverse(s_rev.begin(), s_rev.end());
  string don2 = donyoku(s_rev, n);
  reverse(don2.begin(), don2.end());

  Cnt cnt = count(don1);
  if (cnt.o == k) {
    rep(i, n) {
      if (don1[i] == don2[i]) {
        s[i] = don1[i];
      } else {
        s[i] = '?';
      }
    }
    cout << s << endl;
    return 0;
  }

  if (k == 0) {
    rep(i, n) {
      if (s[i] == '?') {
        s[i] = '.';
      }
    }
  }

  cout << s << endl;
}

/*
    7 3
    ????..?
    ????..o
 */