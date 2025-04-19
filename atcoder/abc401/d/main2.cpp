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
        s[i] = 'o';
      }
    }
  }
  return s;
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
  };

  int cnt_o = 0;
  int cnt_q = 0;
  rep(i, n) {
    if (s[i] == 'o') {
      cnt_o++;
    }
    if (s[i] == '?') {
      cnt_q++;
    }
  }
  if (k - cnt_o == cnt_q) {
    rep(i, n) {
      if (s[i] == '?') {
        s[i] = 'o';
      }
    }
  }

  // reversed_s
  string rev_s = s;
  reverse(rev_s.begin(), rev_s.end());

  {
    string don1 = donyoku(s, n);
    string don2 = donyoku(rev_s, n);
    reverse(don2.begin(), don2.end());
    int cnt_o = 0;
    rep(i, n) {
      if (don1[i] == 'o') {
        cnt_o++;
      }
    }
    // 貪欲においたときに、1通りしかないかつ、Kの値にマッチする場合
    if (cnt_o == k && don1 == don2) {
      rep(i, n) {
        if (don1[i] == '?') {
          don1[i] = '.';
        }
      }
      cout << don1 << endl;
      return 0;
    }

    // 貪欲においたときに、どこにもoを置けない場合
    if (don1 == s) {
      rep(i, n) {
        if (s[i] == '?') {
          s[i] = '.';
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
      cout << s << endl;
      return 0;
    }
  }

  cout << s << endl;
}