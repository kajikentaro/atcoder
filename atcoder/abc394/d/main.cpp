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

signed main() {
  string s;
  cin >> s;
  stack<char> sta;

  map<char, char> ma;
  ma['('] = ')';
  ma['['] = ']';
  ma['<'] = '>';

  int n = s.size();
  rep(i, n) {
    sta.push(s[i]);

    while (sta.size() >= 2) {
      char a = sta.top();
      sta.pop();
      char b = sta.top();
      sta.pop();

      if (ma[b] == a) {
        // do nothing
      } else {
        sta.push(b);
        sta.push(a);
        break;
      }
    }
  };

  if (sta.size() == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
