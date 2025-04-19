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

  Cnt cnt_s = count(s);
  if (cnt_s.o == k) {
    rep(i, n) {
      if (s[i] == '?') s[i] = '.';
    }
    cout << s << endl;
    return 0;
  }

  string don = donyoku(s, n);
  Cnt cnt_don = count(don);
  if (cnt_don.o > k) {
    cout << s << endl;
    return 0;
  }
  if (cnt_don.o == k) {
    vector<int> q_len(n);
    {
      int now_len = 0;
      rrep(i, n) {
        if (s[i] == '?') {
          now_len++;
        } else {
          now_len = 0;
        }
        q_len[i] = now_len;
      }
    }

    rep(i, n) {
      if (s[i] != '?') {
        continue;
      }
      if (q_len[i] % 2 == 0) {
        i += q_len[i] - 1;
        continue;
      }
      int q_len_i = q_len[i];
      rep(j, q_len_i) {
        if (j % 2 == 0) {
          s[i + j] = 'o';
        } else {
          s[i + j] = '.';
        }
      }
      i += q_len_i - 1;
    }
  }
  cout << s << endl;
}