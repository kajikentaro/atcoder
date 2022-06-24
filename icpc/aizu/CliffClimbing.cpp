#include <bits/stdc++.h>

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
using P = pair<int, int>;
const int START = -1;
const int END = -2;
const int EMPTY = -3;

const int RIGHT = 0;
const int LEFT = 1;

struct Foot {
  int h, w;
};

const vector<Foot> step_left = {{0, -1}, {0, -2},  {0, -3},  {1, -1}, {1, -2},
                                {2, -1}, {-1, -1}, {-1, -2}, {-2, -1}};
const vector<Foot> step_right = {{0, 1}, {0, 2},  {0, 3},  {1, 1}, {1, 2},
                                 {2, 1}, {-1, 1}, {-1, 2}, {-2, 1}};
struct Point {
  int h, w, pre_foot, score;
};

bool operator>(const Point &a, const Point &b) { return a.score > b.score; }
bool func() {
  int w, h;
  cin >> w >> h;
  if (w == 0 && h == 0) return false;
  vector<vector<int>> grid(h, vector<int>(w));
  priority_queue<Point, vector<Point>, greater<Point>> que;
  rep(hi, h) rep(wi, w) {
    string a;
    cin >> a;
    if (a == "X")
      grid[hi][wi] = EMPTY;
    else if (a == "T")
      grid[hi][wi] = END;
    else if (a == "S") {
      grid[hi][wi] = START;
      que.push(Point{hi, wi, RIGHT, 0});
      que.push(Point{hi, wi, LEFT, 0});
    } else
      grid[hi][wi] = stoi(a);
  }

  vector<vector<vector<int>>> res(h,
                                  vector<vector<int>>(w, vector<int>(2, -1)));
  while (que.size()) {
    Point p = que.top();
    que.pop();
    if (res[p.h][p.w][p.pre_foot] != -1) continue;
    res[p.h][p.w][p.pre_foot] = p.score;

    const auto step_list = p.pre_foot == RIGHT ? step_left : step_right;
    for (auto step : step_list) {
      Point new_p = p;
      new_p.h += step.h;
      new_p.w += step.w;
      new_p.pre_foot = p.pre_foot == RIGHT ? LEFT : RIGHT;

      if (new_p.h < 0 || new_p.w < 0 || new_p.h >= h || new_p.w >= w) continue;
      if (res[new_p.h][new_p.w][new_p.pre_foot] != -1) continue;
      if (grid[new_p.h][new_p.w] == END) {
        cout << new_p.score << endl;
        return true;
      }
      if (grid[new_p.h][new_p.w] < 0) continue;

      new_p.score += grid[new_p.h][new_p.w];

      que.push(new_p);
    }
  }
  cout << -1 << endl;
  return true;
}
int main() {
  while (func()) {
    ;
  }
}