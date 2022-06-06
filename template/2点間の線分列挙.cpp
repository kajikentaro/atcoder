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
struct Point {
  ll x, y;
};
struct Line {
  ll dx, dy;
  // 切片の分数。i_bottomが0のときはi_topはy軸の値を表す。
  ll i_top;
  ll i_bottom;
};
ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
void simplify(ll &a, ll &b) {
  if (a == 0 && b == 0) {
    throw "同じ点があります";
  } else if (a == 0) {
    b = 1;
  } else if (b == 0) {
    a = 1;
  } else {
    ll g = gcd(abs(a), abs(b));
    a /= g;
    b /= g;
  }
}
Line calc_line(Point a, Point b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;

  if (dx < 0) {
    dx *= -1;
    dy *= -1;
  }
  simplify(dx, dy);

  assert(!(dx == 0 && dy == 0));
  Line res;
  if (dx == 0) {
    res.i_top = a.x;
    res.i_bottom = 0;
  } else if (dy == 0) {
    res.i_bottom = 1;
    res.i_top = a.y;
  } else {
    // それ以外の場合は切片を入れる
    res.i_top = dx * a.y - dy * a.x;
    res.i_bottom = dx;
    ll g = gcd(abs(res.i_top), abs(res.i_bottom));
    res.i_top /= g;
    res.i_bottom /= g;
  }

  // 傾きを入れる
  res.dx = dx;
  res.dy = dy;

  return res;
}
bool operator<(const Line &a, const Line &b) {
  if (a.dx != b.dx) return a.dx < b.dx;
  if (a.dy != b.dy) return a.dy < b.dy;
  if (a.i_top != b.i_top) return a.i_top < b.i_top;
  if (a.i_bottom != b.i_bottom) return a.i_bottom < b.i_bottom;
  return false;
}
int main() {
  ll n, k;
  cin >> n >> k;
  vector<Point> points(n);
  // 点を入力
  rep(i, n) cin >> points[i].x >> points[i].y;

  // 線分とその個数を列挙する
  map<Line, ll> lines;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      Line res = calc_line(points[i], points[j]);
      lines[res]++;
    }
  }
}
/*
この問題とは関係ないが、3点が同一線上にあるかどうかは、
(x_1 - x_0) * (y_2 - y_0) == (x_2 - x_0) * (y_1 - y_0)
でわかる
*/