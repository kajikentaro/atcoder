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
struct Spect {
  int x;
  int type;
};
bool operator>(const Spect &a, const Spect &b) { return a.x > b.x; }
int main() {
  int n;
  cin >> n;
  vector<int> line(2e5 + 10);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    line[x]++;
    line[y]--;
  }

  int now_on_cnt = 0;

  int status = 0;
  rep(i, 2e5 + 10) {
    now_on_cnt += line[i];

    if (status == 0 && now_on_cnt > 0) {
      cout << i << " ";
      status = 1;
    }
    if (status == 1 && now_on_cnt == 0) {
      cout << i << endl;
      status = 0;
    }
  }
}