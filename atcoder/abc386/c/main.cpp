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

bool func() {
  int k;
  string s, t;
  cin >> k >> s >> t;
  int sn = s.size();
  int tn = t.size();
  if (sn == tn) {
    int changed = 0;
    rep(i, sn) {
      if (s[i] != t[i]) {
        changed++;
      }
    }

    if (changed <= 1) {
      return true;
    }

    return false;
  };

  if (sn < tn) {
    swap(sn, tn);
    swap(s, t);
  }

  // tn is short
  int ti = 0;
  int si = 0;
  int changed = 0;
  while (si < sn) {
    if (s[si] != t[ti]) {
      si++;
      changed++;
      continue;
    }
    ti++;
    si++;
  }

  if (changed <= 1) {
    return true;
  }
  return false;
}

signed main() {
  if (func()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}