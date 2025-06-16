#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> points(n);
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    points[i] = a + b + c;
  }

  vector<int> points_backup = points;
  sort(points.begin(), points.end());

  rep(i, n) {
    int score = points_backup[i] + 300;
    auto itr = upper_bound(points.begin(), points.end(), score);
    int idx = itr - points.begin();
    int ans = n - idx + 1;
    if (ans <= k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}