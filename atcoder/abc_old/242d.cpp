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
int main() {
  string s;
  int q;
  cin >> s >> q;

  rep(i, q) {
    ll t, k;
    cin >> t >> k;
    k--;

    ll unit_no;
    ll unit_k;
    if (t >= 60) {
      unit_no = 0;
      unit_k = k;
    } else {
      ll unit_size = 1ll << t;
      unit_no = k / unit_size;
      unit_k = k % unit_size;
    }

    ll unit_start_alphabet = 0;
    if (s[unit_no] == 'B') unit_start_alphabet = 1;
    if (s[unit_no] == 'C') unit_start_alphabet = 2;

    ll point = 0;
    for (ll i = 0; i < t; i++) {
      if (unit_k == 0) {
        point += t - i;
        break;
      }
      if (unit_k % 2 == 1) {
        point += 2;
      } else {
        point += 1;
      }
      unit_k /= 2;
    }
    string alphabet[] = {"A", "B", "C"};
    cout << alphabet[(point + unit_start_alphabet) % 3] << endl;
  }
}