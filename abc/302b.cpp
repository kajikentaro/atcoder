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
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  rep(hi_r, h) {
    rep(wi_r, w) {
      int dir[][2] = {{0, 1},  {1, 0},   {1, 1},  {0, -1},
                      {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
      for (auto d : dir) {
        string atcoder = "snuke";

        int hi = hi_r;
        int wi = wi_r;
        bool is_ok = true;
        for (auto a : atcoder) {
          char cursor = '#';
          if (hi >= 0 && wi >= 0 && hi < h && wi < w) cursor = s[hi][wi];
          if (cursor != a) {
            is_ok = false;
          }
          hi += d[0];
          wi += d[1];
        }
        if (!is_ok) {
          continue;
        }
        // answer
        hi = hi_r;
        wi = wi_r;
        for (auto _ : atcoder) {
          cout << hi + 1 << " " << wi + 1 << endl;
          hi += d[0];
          wi += d[1];
        }
        return 0;
      }
    }
  }
}